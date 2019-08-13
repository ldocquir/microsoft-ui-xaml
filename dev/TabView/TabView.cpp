﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "common.h"
#include "TabView.h"
#include "TabViewAutomationPeer.h"
#include "DoubleUtil.h"
#include "RuntimeProfiler.h"
#include "ResourceAccessor.h"
#include "SharedHelpers.h"
#include <Vector.h>
#include "TabViewItem.h"

static constexpr double c_tabMinimumWidth = 48.0;
static constexpr double c_tabMaximumWidth = 200.0;

static constexpr wstring_view c_tabViewItemMinWidthName{ L"TabViewItemMinWidth"sv };
static constexpr wstring_view c_tabViewItemMaxWidthName{ L"TabViewItemMaxWidth"sv };

// TODO: what is the right number and should this be customizable?
static constexpr double c_scrollAmount = 50.0;

TabView::TabView()
{
    __RP_Marker_ClassById(RuntimeProfiler::ProfId_TabView);

    auto items = winrt::make<Vector<winrt::IInspectable>>();
    SetValue(s_ItemsProperty, items);

    SetDefaultStyleKey(this);

    Loaded({ this, &TabView::OnLoaded });
    SizeChanged({ this, &TabView::OnSizeChanged });
    m_selectionModel.SingleSelect(true);
}

void TabView::OnApplyTemplate()
{
    winrt::IControlProtected controlProtected{ *this };

    m_tabContentPresenter.set(GetTemplateChildT<winrt::ContentPresenter>(L"TabContentPresenter", controlProtected));
    m_rightContentPresenter.set(GetTemplateChildT<winrt::ContentPresenter>(L"RightContentPresenter", controlProtected));

    m_leftContentColumn.set(GetTemplateChildT<winrt::ColumnDefinition>(L"LeftContentColumn", controlProtected));
    m_tabColumn.set(GetTemplateChildT<winrt::ColumnDefinition>(L"TabColumn", controlProtected));
    m_addButtonColumn.set(GetTemplateChildT<winrt::ColumnDefinition>(L"AddButtonColumn", controlProtected));
    m_rightContentColumn.set(GetTemplateChildT<winrt::ColumnDefinition>(L"RightContentColumn", controlProtected));

    m_tabContainerGrid.set(GetTemplateChildT<winrt::Grid>(L"TabContainerGrid", controlProtected));
    m_scrollViewer.set(GetTemplateChildT<winrt::FxScrollViewer>(L"ScrollViewer", controlProtected));

    m_rootGrid.set(GetTemplateChildT<winrt::Grid>(L"RepeaterGrid", controlProtected));
    m_repeaterDragOverRevoker = m_rootGrid.get().DragOver(winrt::auto_revoke, { this, &TabView::OnRepeaterDragOver });
    m_repeaterDropRevoker = m_rootGrid.get().Drop(winrt::auto_revoke, { this, &TabView::OnRepeaterDrop });

    m_scrollViewerLoadedRevoker = m_scrollViewer.get().Loaded(winrt::auto_revoke, { this, &TabView::OnScrollViewerLoaded });

    m_itemsRepeater.set([this, controlProtected]() {
        auto repeater = GetTemplateChildT<winrt::ItemsRepeater>(L"TabItemsRepeater", controlProtected);
        if (repeater)
        {
            m_listViewLoadedRevoker = repeater.Loaded(winrt::auto_revoke, { this, &TabView::OnListViewLoaded });
            m_repeaterElementPreparedRevoker = repeater.ElementPrepared(winrt::auto_revoke, { this, &TabView::OnRepeaterElementPrepared });
            m_repeaterElementIndexChangedRevoker = repeater.ElementIndexChanged(winrt::auto_revoke, { this, &TabView::OnRepeaterElementIndexChanged });
        }
        return repeater;
        }());

    m_selectionChangedRevoker = m_selectionModel.SelectionChanged(winrt::auto_revoke, { this, &TabView::OnSelectionChanged });

    m_addButton.set([this, controlProtected]() {
        auto addButton = GetTemplateChildT<winrt::Button>(L"AddButton", controlProtected);
        if (addButton)
        {
            // Do localization for the add button
            if (winrt::AutomationProperties::GetName(addButton).empty())
            {
                auto addButtonName = ResourceAccessor::GetLocalizedStringResource(SR_TabViewAddButtonName);
                winrt::AutomationProperties::SetName(addButton, addButtonName);
            }

            auto toolTip = winrt::ToolTipService::GetToolTip(addButton);
            if (!toolTip)
            {
                winrt::ToolTip tooltip = winrt::ToolTip();
                tooltip.Content(box_value(ResourceAccessor::GetLocalizedStringResource(SR_TabViewAddButtonTooltip)));
                winrt::ToolTipService::SetToolTip(addButton, tooltip);
            }

            m_addButtonClickRevoker = addButton.Click(winrt::auto_revoke, { this, &TabView::OnAddButtonClick });
        }
        return addButton;
        }());

    if (SharedHelpers::IsRS3OrHigher())
    {
        winrt::KeyboardAccelerator keyboardAccelerator;
        keyboardAccelerator.Key(winrt::VirtualKey::F4);
        keyboardAccelerator.Modifiers(winrt::VirtualKeyModifiers::Control);
        keyboardAccelerator.Invoked({ this, &TabView::OnCtrlF4Invoked });
        keyboardAccelerator.ScopeOwner(*this);
        KeyboardAccelerators().Append(keyboardAccelerator);
    }

    UpdateItemsSource();
}

void TabView::UpdateItemsSource()
{
    if (auto repeater = m_itemsRepeater.get())
    {
        if (ItemsSource())
        {
            repeater.ItemsSource(ItemsSource());
           
        }
        else
        {
            repeater.ItemsSource(Items());
        }

        m_selectionModel.Source(repeater.ItemsSourceView());
        m_collectionChangedRevoker = repeater.ItemsSourceView().CollectionChanged(winrt::auto_revoke, { this, &TabView::OnItemsChanged });               
    }
}

void TabView::OnItemsPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args)
{
    UpdateItemsSource();
}

void TabView::OnItemsSourcePropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args)
{
    UpdateItemsSource();
}

void TabView::OnSelectedIndexPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args)
{
    UpdateSelectedIndex();
}

void TabView::OnSelectedItemPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args)
{
    UpdateSelectedItem();
}

void TabView::OnTabWidthModePropertyChanged(const winrt::DependencyPropertyChangedEventArgs&)
{
    UpdateTabWidths();
}

void TabView::OnAddButtonClick(const winrt::IInspectable&, const winrt::RoutedEventArgs& args)
{
    m_addButtonClickEventSource(*this, args);
}

winrt::AutomationPeer TabView::OnCreateAutomationPeer()
{
    return winrt::make<TabViewAutomationPeer>(*this);
}

void TabView::OnLoaded(const winrt::IInspectable&, const winrt::RoutedEventArgs&)
{
    UpdateTabContent();
}

void TabView::OnListViewLoaded(const winrt::IInspectable&, const winrt::RoutedEventArgs& args)
{
    if (ReadLocalValue(s_SelectedIndexProperty) != winrt::DependencyProperty::UnsetValue())
    {
        UpdateSelectedIndex();
    }
    if (ReadLocalValue(s_SelectedItemProperty) != winrt::DependencyProperty::UnsetValue())
    {
        UpdateSelectedItem();
    }

    if (auto repeater = m_itemsRepeater.get())
    {
        if (auto selectedIndex = m_selectionModel.SelectedIndex())
        {
            SelectedIndex(selectedIndex.GetAt(0));
            SelectedItem(m_selectionModel.SelectedItem());
        }
    }
}

void TabView::OnScrollViewerLoaded(const winrt::IInspectable&, const winrt::RoutedEventArgs& args)
{
    if (auto && scrollViewer = m_scrollViewer.get())
    {
        m_scrollDecreaseButton.set([this, scrollViewer]() {
            auto decreaseButton = SharedHelpers::FindInVisualTreeByName(scrollViewer, L"ScrollDecreaseButton").as<winrt::RepeatButton>();
            m_scrollDecreaseClickRevoker = decreaseButton.Click(winrt::auto_revoke, { this, &TabView::OnScrollDecreaseClick });
            return decreaseButton;
            }());

        m_scrollIncreaseButton.set([this, scrollViewer]() {
            auto increaseButton = SharedHelpers::FindInVisualTreeByName(scrollViewer, L"ScrollIncreaseButton").as<winrt::RepeatButton>();
            m_scrollIncreaseClickRevoker = increaseButton.Click(winrt::auto_revoke, { this, &TabView::OnScrollIncreaseClick });
            return increaseButton;
            }());
    }

    UpdateTabWidths();
}

void TabView::OnSizeChanged(const winrt::IInspectable&, const winrt::SizeChangedEventArgs&)
{
    UpdateTabWidths();
}

void TabView::OnItemsChanged(const winrt::IInspectable& dataSource, const winrt::NotifyCollectionChangedEventArgs& args)
{
    int numItems = static_cast<int>(Items().Size());
    if (args.Action() == winrt::NotifyCollectionChangedAction::Remove && numItems > 0)
    {
        if (SelectedIndex() == static_cast<int32_t>(args.OldStartingIndex()))
        {
            // Find the closest tab to select instead.
            int startIndex = static_cast<int>(args.OldStartingIndex());
            if (startIndex >= numItems)
            {
                startIndex = numItems - 1;
            }
            int index = startIndex;

            do
            {
                auto nextItem = ContainerFromIndex(index).as<winrt::TabViewItem>();

                if (nextItem && nextItem.IsEnabled() && nextItem.Visibility() == winrt::Visibility::Visible)
                {
                    //SelectedItem(Items().GetAt(index));
                    m_selectionModel.Select(index);
                    break;
                }

                // try the next item
                index++;
                if (index >= numItems)
                {
                    index = 0;
                }
            } while (index != startIndex);
        }
    }

    UpdateTabWidths();
}

void TabView::OnSelectionChanged(const winrt::SelectionModel& sender, const winrt::SelectionModelSelectionChangedEventArgs& args)
{
    SelectedItem(sender.SelectedItem());
    if (sender.SelectedIndex())
    {
        SelectedIndex(sender.SelectedIndex().GetAt(0));
    }
    UpdateTabContent();
    // TODO: Make a selection changed event args instance.
    m_selectionChangedEventSource(*this, nullptr); 
}

void TabView::StartDragAnimations(int dragItemIndex, double dragElementWidth)
{
    auto compositor = winrt::Window::Current().Compositor();
    auto props = winrt::ElementCompositionPreview::GetPointerPositionPropertySet(m_itemsRepeater.get());
    // yfactor * smoothStepFunction
    constexpr auto expr = L"(Clamp((200 + (pointer.Position.Y - top)) / 200, 0, 1)) *  (halfDraggingElementWidth * (2 / Pi) * ATan((Pi / 2) * -(pointer.Position.X - center)) * (pointer.Position.X < center ? canInsertBefore : 1) * (pointer.Position.X > center ? canInsertAfter : 1))";

    if (!m_dragAnimation)
    {
        m_dragAnimation = compositor.CreateExpressionAnimation();

        m_dragAnimation.SetReferenceParameter(L"pointer", props);
        m_dragAnimation.Target(L"Translation.X");
    }

    int startIndex = 0;
    int count = m_itemsRepeater.get().ItemsSourceView().Count();
    for (int i = 0; i < count; i++)
    {
        if (auto element = m_itemsRepeater.get().TryGetElement(i))
        {
            m_dragAnimation.Expression(expr);

            winrt::ElementCompositionPreview::SetIsTranslationEnabled(element, true);
            auto bounds = winrt::LayoutInformation::GetLayoutSlot(element.as<winrt::FrameworkElement>());
            bool canInsertBefore = i >= startIndex;
            bool canInsertAfter = i <= startIndex + count;

            m_dragAnimation.SetScalarParameter(L"canInsertBefore", canInsertBefore ? 1.0f : -1.0f);
            m_dragAnimation.SetScalarParameter(L"canInsertAfter", canInsertAfter ? 1.0f : -1.0f);
            m_dragAnimation.SetScalarParameter(L"top", (float)bounds.Y);
            m_dragAnimation.SetScalarParameter(L"center", (float)(bounds.X + 0.5 * bounds.Width));
            m_dragAnimation.SetScalarParameter(L"halfDraggingElementWidth", (float)(dragElementWidth * 0.4));
            element.StartAnimation(m_dragAnimation);
            element.as<winrt::FrameworkElement>().Tag(m_dragAnimation);
        }
    }
}

void TabView::StopDragAnimations()
{
    int count = m_itemsRepeater.get().ItemsSourceView().Count();
    for (int i = 0; i < count; i++)
    {
        if (auto element = m_itemsRepeater.get().TryGetElement(i))
        {
            if (auto animation = element.as<winrt::FrameworkElement>().Tag().try_as<winrt::ExpressionAnimation>())
            {
                animation.Expression(L"0");
                element.StartAnimation(animation);
                // Stop animation does not seem to really stop the animation :/
                //element.StopAnimation(animation);
            }
        }
    }
}

void TabView::OnItemDragStarting(const winrt::TabViewItem& item, const winrt::DragStartingEventArgs& args)
{
    CloneDragVisual(item, args);
}

winrt::IAsyncAction TabView::CloneDragVisual(const winrt::TabViewItem& item, const winrt::DragStartingEventArgs& args)
{
    m_draggedItemIndex = m_itemsRepeater.get().GetElementIndex(item);

    auto deferral = args.GetDeferral();
    m_draggedItem = Items().GetAt(m_draggedItemIndex);

    StartDragAnimations(m_draggedItemIndex, item.ActualWidth());

    args.Data().RequestedOperation(winrt::DataPackageOperation::Move);
    args.Data().SetText(L"ItemMoving..");
    args.Data().Properties().Title(L"Hello world");

    m_dataPackageOperationCompletedRevoker = args.Data().OperationCompleted(winrt::auto_revoke, { this, &TabView::OnDataPackageOperationCompleted });

    // take a snapshot of the item because we are removing it from the source.
    auto dragUI = args.DragUI();
    auto renderTargetBitmap = winrt::RenderTargetBitmap();
    co_await renderTargetBitmap.RenderAsync(item);
    auto buffer = co_await renderTargetBitmap.GetPixelsAsync();
    auto bitmap = winrt::SoftwareBitmap::CreateCopyFromBuffer(buffer,
        winrt::BitmapPixelFormat::Bgra8,
        renderTargetBitmap.PixelWidth(),
        renderTargetBitmap.PixelHeight(),
        winrt::BitmapAlphaMode::Premultiplied);
    dragUI.SetContentFromSoftwareBitmap(bitmap);

    Items().RemoveAt(m_draggedItemIndex);

    deferral.Complete();
}

void TabView::OnRepeaterDragOver(const winrt::IInspectable& sender, const winrt::DragEventArgs& args)
{
    args.AcceptedOperation(winrt::DataPackageOperation::Move);
    args.DragUIOverride().IsGlyphVisible(true);
    args.DragUIOverride().IsContentVisible(true);
}

void TabView::OnRepeaterDrop(const winrt::IInspectable& sender, const winrt::DragEventArgs& args)
{
    StopDragAnimations();
    int index = GetInsertionIndex(args.GetPosition(m_itemsRepeater.get()), 100 /* dropped item width */);

    if (index > 0)
    {
        Items().InsertAt(index, m_draggedItem);
        m_draggedItemIndex = -1;
        m_draggedItem = nullptr;
    }
}

int TabView::GetInsertionIndex(const winrt::Point& position, int droppedElementWidth)
{
    int count = m_itemsRepeater.get().ItemsSourceView().Count();
    auto dropBetweenScale = 0.5;
    for (int i = 0; i < count; i++)
    {
        if (auto element = m_itemsRepeater.get().TryGetElement(i))
        {
            auto bounds = winrt::LayoutInformation::GetLayoutSlot(element.as<winrt::FrameworkElement>());
            if (position.X < (bounds.X + dropBetweenScale * bounds.Width))
            {
                return i;
            }
        }
    }

    return -1;
}

void TabView::OnDataPackageOperationCompleted(const winrt::DataPackage& sender, const winrt::OperationCompletedEventArgs& args)
{
    DispatcherHelper dispatcherHelper(*this);
    dispatcherHelper.RunAsync([this]()
        {
            if (m_draggedItemIndex >= 0)
            {
                // insert it back 
                Items().InsertAt(m_draggedItemIndex, m_draggedItem);
                UpdateLayout();

                const auto item = m_draggedItem;
                auto tab = ContainerFromItem(item).try_as<winrt::TabViewItem>();

                if (!tab)
                {
                    if (auto fe = item.try_as<winrt::FrameworkElement>())
                    {
                        tab = winrt::VisualTreeHelper::GetParent(fe).try_as<winrt::TabViewItem>();
                    }
                }

                if (!tab)
                {
                    // This is a fallback scenario for tabs without a data context
                    auto numItems = static_cast<int>(Items().Size());
                    for (int i = 0; i < numItems; i++)
                    {
                        auto tabItem = ContainerFromIndex(i).try_as<winrt::TabViewItem>();
                        if (tabItem.Content() == item)
                        {
                            tab = tabItem;
                            break;
                        }
                    }
                }

                auto myArgs = winrt::make_self<TabViewTabDraggedOutsideEventArgs>(item, tab);
                m_tabDraggedOutsideEventSource(*this, *myArgs);

              
                m_draggedItemIndex = -1;
                m_draggedItem = nullptr;
            }

            StopDragAnimations();

           
        });
}

void TabView::UpdateTabContent()
{
    if (auto tabContentPresenter = m_tabContentPresenter.get())
    {
        if (!SelectedItem())
        { 
            tabContentPresenter.Content(nullptr);
            tabContentPresenter.ContentTemplate(nullptr);
            tabContentPresenter.ContentTemplateSelector(nullptr);
        }
        else
        {
            if (auto container = ContainerFromItem(SelectedItem()).as<winrt::TabViewItem>())
            {
                tabContentPresenter.Content(container.Content());
                tabContentPresenter.ContentTemplate(container.ContentTemplate());
                tabContentPresenter.ContentTemplateSelector(container.ContentTemplateSelector());
            }
        }
    }
}

void TabView::CloseTab(winrt::TabViewItem const& container)
{
    if (auto repeater = m_itemsRepeater.get())
    {
        int index = repeater.GetElementIndex(container);
        auto args = winrt::make_self<TabViewTabClosingEventArgs>(repeater.ItemsSourceView().GetAt(index));
        m_tabClosingEventSource(*this, *args);

        if (!args->Cancel())
        {
            Items().RemoveAt(index);
        }
    }
}

void TabView::OnScrollDecreaseClick(const winrt::IInspectable&, const winrt::RoutedEventArgs&)
{
    if (auto scrollViewer = m_scrollViewer.get())
    {
        scrollViewer.ChangeView(std::max(0.0, scrollViewer.HorizontalOffset() - c_scrollAmount), nullptr, nullptr);
    }
}

void TabView::OnScrollIncreaseClick(const winrt::IInspectable&, const winrt::RoutedEventArgs&)
{
    if (auto scrollViewer = m_scrollViewer.get())
    {
        scrollViewer.ChangeView(std::min(scrollViewer.ScrollableWidth(), scrollViewer.HorizontalOffset() + c_scrollAmount), nullptr, nullptr);
    }
}

void TabView::UpdateTabWidths()
{
    double tabWidth = std::numeric_limits<double>::quiet_NaN();

    if (auto tabGrid = m_tabContainerGrid.get())
    {
        // Add up width taken by custom content and + button
        double widthTaken = 0.0;
        if (auto leftContentColumn = m_leftContentColumn.get())
        {
            widthTaken += leftContentColumn.ActualWidth();
        }
        if (auto addButtonColumn = m_addButtonColumn.get())
        {
            widthTaken += addButtonColumn.ActualWidth();
        }
        if (auto && rightContentColumn = m_rightContentColumn.get())
        {
            if (auto rightContentPresenter = m_rightContentPresenter.get())
            {
                winrt::Size rightContentSize = rightContentPresenter.DesiredSize();
                rightContentColumn.MinWidth(rightContentSize.Width);
                widthTaken += rightContentSize.Width;
            }
        }

        if (auto tabColumn = m_tabColumn.get())
        {
            auto availableWidth = ActualWidth() - widthTaken;

            if (TabWidthMode() == winrt::TabViewWidthMode::SizeToContent)
            {
                tabColumn.MaxWidth(availableWidth);
                tabColumn.Width(winrt::GridLengthHelper::FromValueAndType(1.0, winrt::GridUnitType::Auto));
            }
            else if (TabWidthMode() == winrt::TabViewWidthMode::Equal)
            {
                // Tabs should all be the same size, proportional to the amount of space.
                double minTabWidth = unbox_value<double>(SharedHelpers::FindResource(c_tabViewItemMinWidthName, winrt::Application::Current().Resources(), box_value(c_tabMinimumWidth)));
                double maxTabWidth = unbox_value<double>(SharedHelpers::FindResource(c_tabViewItemMaxWidthName, winrt::Application::Current().Resources(), box_value(c_tabMaximumWidth)));

                // Calculate the proportional width of each tab given the width of the ScrollViewer.
                auto padding = Padding();
                double tabWidthForScroller = (availableWidth - (padding.Left + padding.Right)) / (double)(Items().Size());

                tabWidth = std::clamp(tabWidthForScroller, minTabWidth, maxTabWidth);

                // If the min tab width causes the ScrollViewer to scroll, show the increase/decrease buttons.
                auto decreaseButton = m_scrollDecreaseButton.get();
                auto increaseButton = m_scrollIncreaseButton.get();
                if (decreaseButton && increaseButton)
                {
                    if (tabWidthForScroller < tabWidth)
                    {
                        decreaseButton.Visibility(winrt::Visibility::Visible);
                        increaseButton.Visibility(winrt::Visibility::Visible);
                    }
                    else
                    {
                        decreaseButton.Visibility(winrt::Visibility::Collapsed);
                        increaseButton.Visibility(winrt::Visibility::Collapsed);
                    }
                }

                // Size tab column to needed size
                tabColumn.MaxWidth(availableWidth);
                auto requiredWidth = tabWidth * Items().Size();
                if (requiredWidth >= availableWidth)
                {
                    tabColumn.Width(winrt::GridLengthHelper::FromPixels(availableWidth));
                }
                else
                {
                    tabColumn.Width(winrt::GridLengthHelper::FromValueAndType(1.0, winrt::GridUnitType::Auto));
                }
            }
        }
    }

    for (auto item : Items())
    {
        // Set the calculated width on each tab.
        if (auto container = ContainerFromItem(item).as<winrt::TabViewItem>())
        {
            container.Width(tabWidth);
        }
    }
}


void TabView::UpdateSelectedItem()
{
    uint32_t index;
    if (Items().IndexOf(SelectedItem(), index))
    {
        m_selectionModel.Select(index);
    }
}

void TabView::UpdateSelectedIndex()
{
    if (!m_selectionModel.SelectedIndex() ||
        m_selectionModel.SelectedIndex().GetAt(0) != SelectedIndex())
    {
        m_selectionModel.Select(SelectedIndex());
    }
}

winrt::DependencyObject TabView::ContainerFromItem(winrt::IInspectable const& item)
{
    if (auto repeater = m_itemsRepeater.get())
    {
        uint32_t index;
        if (Items().IndexOf(item, index))
        {
            return repeater.TryGetElement(index);
        }
    }
    return nullptr;
}

winrt::DependencyObject TabView::ContainerFromIndex(int index)
{
    if (auto repeater = m_itemsRepeater.get())
    {
        return repeater.TryGetElement(index);
    }
    return nullptr;
}

void TabView::OnCtrlF4Invoked(const winrt::KeyboardAccelerator& sender, const winrt::KeyboardAcceleratorInvokedEventArgs& args)
{
    if (auto selectedTab = SelectedItem().try_as<winrt::TabViewItem>())
    {
        if (selectedTab.IsCloseable())
        {
            // Close the tab on ctrl + F4
            CloseTab(selectedTab);
            args.Handled(true);
        }
    }
}

void TabView::OnRepeaterElementPrepared(const winrt::ItemsRepeater& sender, const winrt::ItemsRepeaterElementPreparedEventArgs& args)
{
    if (auto item = args.Element().try_as<winrt::TabViewItem>())
    {
        auto tabItem = winrt::get_self<TabViewItem>(item);
        tabItem->RepeatedIndex(args.Index());
        tabItem->SelectionModel(m_selectionModel);
    }
}

void TabView::OnRepeaterElementIndexChanged(const winrt::ItemsRepeater& sender, const winrt::ItemsRepeaterElementIndexChangedEventArgs& args)
{
    if (auto item = args.Element().try_as<winrt::TabViewItem>())
    {
        auto tabItem = winrt::get_self<TabViewItem>(item);
        tabItem->RepeatedIndex(args.NewIndex());
    }
}
