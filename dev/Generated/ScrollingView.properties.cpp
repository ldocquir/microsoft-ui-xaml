// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// DO NOT EDIT! This file was generated by CustomTasks.DependencyPropertyCodeGen
#include "pch.h"
#include "common.h"
#include "ScrollingView.h"

CppWinRTActivatableClassWithDPFactory(ScrollingView)

GlobalDependencyProperty ScrollingViewProperties::s_ComputedHorizontalScrollBarVisibilityProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_ComputedVerticalScrollBarVisibilityProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_ContentProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_ContentOrientationProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_HorizontalAnchorRatioProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_HorizontalScrollBarVisibilityProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_HorizontalScrollChainModeProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_HorizontalScrollControllerProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_HorizontalScrollModeProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_HorizontalScrollRailModeProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_IgnoredInputKindProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_MaxZoomFactorProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_MinZoomFactorProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_ScrollingPresenterProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_VerticalAnchorRatioProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_VerticalScrollBarVisibilityProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_VerticalScrollChainModeProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_VerticalScrollControllerProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_VerticalScrollModeProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_VerticalScrollRailModeProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_ZoomChainModeProperty{ nullptr };
GlobalDependencyProperty ScrollingViewProperties::s_ZoomModeProperty{ nullptr };

ScrollingViewProperties::ScrollingViewProperties()
    : m_anchorRequestedEventSource{static_cast<ScrollingView*>(this)}
    , m_bringingIntoViewEventSource{static_cast<ScrollingView*>(this)}
    , m_extentChangedEventSource{static_cast<ScrollingView*>(this)}
    , m_scrollAnimationStartingEventSource{static_cast<ScrollingView*>(this)}
    , m_scrollCompletedEventSource{static_cast<ScrollingView*>(this)}
    , m_stateChangedEventSource{static_cast<ScrollingView*>(this)}
    , m_viewChangedEventSource{static_cast<ScrollingView*>(this)}
    , m_zoomAnimationStartingEventSource{static_cast<ScrollingView*>(this)}
    , m_zoomCompletedEventSource{static_cast<ScrollingView*>(this)}
{
    EnsureProperties();
}

void ScrollingViewProperties::EnsureProperties()
{
    if (!s_ComputedHorizontalScrollBarVisibilityProperty)
    {
        s_ComputedHorizontalScrollBarVisibilityProperty =
            InitializeDependencyProperty(
                L"ComputedHorizontalScrollBarVisibility",
                winrt::name_of<winrt::Visibility>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::Visibility>::BoxValueIfNecessary(ScrollingView::s_defaultComputedHorizontalScrollBarVisibility),
                winrt::PropertyChangedCallback(&OnComputedHorizontalScrollBarVisibilityPropertyChanged));
    }
    if (!s_ComputedVerticalScrollBarVisibilityProperty)
    {
        s_ComputedVerticalScrollBarVisibilityProperty =
            InitializeDependencyProperty(
                L"ComputedVerticalScrollBarVisibility",
                winrt::name_of<winrt::Visibility>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::Visibility>::BoxValueIfNecessary(ScrollingView::s_defaultComputedVerticalScrollBarVisibility),
                winrt::PropertyChangedCallback(&OnComputedVerticalScrollBarVisibilityPropertyChanged));
    }
    if (!s_ContentProperty)
    {
        s_ContentProperty =
            InitializeDependencyProperty(
                L"Content",
                winrt::name_of<winrt::UIElement>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::UIElement>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnContentPropertyChanged));
    }
    if (!s_ContentOrientationProperty)
    {
        s_ContentOrientationProperty =
            InitializeDependencyProperty(
                L"ContentOrientation",
                winrt::name_of<winrt::ScrollingContentOrientation>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingContentOrientation>::BoxValueIfNecessary(ScrollingView::s_defaultContentOrientation),
                winrt::PropertyChangedCallback(&OnContentOrientationPropertyChanged));
    }
    if (!s_HorizontalAnchorRatioProperty)
    {
        s_HorizontalAnchorRatioProperty =
            InitializeDependencyProperty(
                L"HorizontalAnchorRatio",
                winrt::name_of<double>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<double>::BoxValueIfNecessary(ScrollingView::s_defaultAnchorRatio),
                winrt::PropertyChangedCallback(&OnHorizontalAnchorRatioPropertyChanged));
    }
    if (!s_HorizontalScrollBarVisibilityProperty)
    {
        s_HorizontalScrollBarVisibilityProperty =
            InitializeDependencyProperty(
                L"HorizontalScrollBarVisibility",
                winrt::name_of<winrt::ScrollingScrollBarVisibility>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingScrollBarVisibility>::BoxValueIfNecessary(ScrollingView::s_defaultHorizontalScrollBarVisibility),
                winrt::PropertyChangedCallback(&OnHorizontalScrollBarVisibilityPropertyChanged));
    }
    if (!s_HorizontalScrollChainModeProperty)
    {
        s_HorizontalScrollChainModeProperty =
            InitializeDependencyProperty(
                L"HorizontalScrollChainMode",
                winrt::name_of<winrt::ScrollingChainMode>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingChainMode>::BoxValueIfNecessary(ScrollingView::s_defaultHorizontalScrollChainMode),
                winrt::PropertyChangedCallback(&OnHorizontalScrollChainModePropertyChanged));
    }
    if (!s_HorizontalScrollControllerProperty)
    {
        s_HorizontalScrollControllerProperty =
            InitializeDependencyProperty(
                L"HorizontalScrollController",
                winrt::name_of<winrt::IScrollController>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::IScrollController>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnHorizontalScrollControllerPropertyChanged));
    }
    if (!s_HorizontalScrollModeProperty)
    {
        s_HorizontalScrollModeProperty =
            InitializeDependencyProperty(
                L"HorizontalScrollMode",
                winrt::name_of<winrt::ScrollingScrollMode>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingScrollMode>::BoxValueIfNecessary(ScrollingView::s_defaultHorizontalScrollMode),
                winrt::PropertyChangedCallback(&OnHorizontalScrollModePropertyChanged));
    }
    if (!s_HorizontalScrollRailModeProperty)
    {
        s_HorizontalScrollRailModeProperty =
            InitializeDependencyProperty(
                L"HorizontalScrollRailMode",
                winrt::name_of<winrt::ScrollingRailMode>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingRailMode>::BoxValueIfNecessary(ScrollingView::s_defaultHorizontalScrollRailMode),
                winrt::PropertyChangedCallback(&OnHorizontalScrollRailModePropertyChanged));
    }
    if (!s_IgnoredInputKindProperty)
    {
        s_IgnoredInputKindProperty =
            InitializeDependencyProperty(
                L"IgnoredInputKind",
                winrt::name_of<winrt::ScrollingInputKinds>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingInputKinds>::BoxValueIfNecessary(ScrollingView::s_defaultIgnoredInputKind),
                winrt::PropertyChangedCallback(&OnIgnoredInputKindPropertyChanged));
    }
    if (!s_MaxZoomFactorProperty)
    {
        s_MaxZoomFactorProperty =
            InitializeDependencyProperty(
                L"MaxZoomFactor",
                winrt::name_of<double>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<double>::BoxValueIfNecessary(ScrollingView::s_defaultMaxZoomFactor),
                winrt::PropertyChangedCallback(&OnMaxZoomFactorPropertyChanged));
    }
    if (!s_MinZoomFactorProperty)
    {
        s_MinZoomFactorProperty =
            InitializeDependencyProperty(
                L"MinZoomFactor",
                winrt::name_of<double>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<double>::BoxValueIfNecessary(ScrollingView::s_defaultMinZoomFactor),
                winrt::PropertyChangedCallback(&OnMinZoomFactorPropertyChanged));
    }
    if (!s_ScrollingPresenterProperty)
    {
        s_ScrollingPresenterProperty =
            InitializeDependencyProperty(
                L"ScrollingPresenter",
                winrt::name_of<winrt::ScrollingPresenter>(),
                winrt::name_of<winrt::ScrollingView>(),
                true /* isAttached */,
                ValueHelper<winrt::ScrollingPresenter>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnScrollingPresenterPropertyChanged));
    }
    if (!s_VerticalAnchorRatioProperty)
    {
        s_VerticalAnchorRatioProperty =
            InitializeDependencyProperty(
                L"VerticalAnchorRatio",
                winrt::name_of<double>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<double>::BoxValueIfNecessary(ScrollingView::s_defaultAnchorRatio),
                winrt::PropertyChangedCallback(&OnVerticalAnchorRatioPropertyChanged));
    }
    if (!s_VerticalScrollBarVisibilityProperty)
    {
        s_VerticalScrollBarVisibilityProperty =
            InitializeDependencyProperty(
                L"VerticalScrollBarVisibility",
                winrt::name_of<winrt::ScrollingScrollBarVisibility>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingScrollBarVisibility>::BoxValueIfNecessary(ScrollingView::s_defaultVerticalScrollBarVisibility),
                winrt::PropertyChangedCallback(&OnVerticalScrollBarVisibilityPropertyChanged));
    }
    if (!s_VerticalScrollChainModeProperty)
    {
        s_VerticalScrollChainModeProperty =
            InitializeDependencyProperty(
                L"VerticalScrollChainMode",
                winrt::name_of<winrt::ScrollingChainMode>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingChainMode>::BoxValueIfNecessary(ScrollingView::s_defaultVerticalScrollChainMode),
                winrt::PropertyChangedCallback(&OnVerticalScrollChainModePropertyChanged));
    }
    if (!s_VerticalScrollControllerProperty)
    {
        s_VerticalScrollControllerProperty =
            InitializeDependencyProperty(
                L"VerticalScrollController",
                winrt::name_of<winrt::IScrollController>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::IScrollController>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnVerticalScrollControllerPropertyChanged));
    }
    if (!s_VerticalScrollModeProperty)
    {
        s_VerticalScrollModeProperty =
            InitializeDependencyProperty(
                L"VerticalScrollMode",
                winrt::name_of<winrt::ScrollingScrollMode>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingScrollMode>::BoxValueIfNecessary(ScrollingView::s_defaultVerticalScrollMode),
                winrt::PropertyChangedCallback(&OnVerticalScrollModePropertyChanged));
    }
    if (!s_VerticalScrollRailModeProperty)
    {
        s_VerticalScrollRailModeProperty =
            InitializeDependencyProperty(
                L"VerticalScrollRailMode",
                winrt::name_of<winrt::ScrollingRailMode>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingRailMode>::BoxValueIfNecessary(ScrollingView::s_defaultVerticalScrollRailMode),
                winrt::PropertyChangedCallback(&OnVerticalScrollRailModePropertyChanged));
    }
    if (!s_ZoomChainModeProperty)
    {
        s_ZoomChainModeProperty =
            InitializeDependencyProperty(
                L"ZoomChainMode",
                winrt::name_of<winrt::ScrollingChainMode>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingChainMode>::BoxValueIfNecessary(ScrollingView::s_defaultZoomChainMode),
                winrt::PropertyChangedCallback(&OnZoomChainModePropertyChanged));
    }
    if (!s_ZoomModeProperty)
    {
        s_ZoomModeProperty =
            InitializeDependencyProperty(
                L"ZoomMode",
                winrt::name_of<winrt::ScrollingZoomMode>(),
                winrt::name_of<winrt::ScrollingView>(),
                false /* isAttached */,
                ValueHelper<winrt::ScrollingZoomMode>::BoxValueIfNecessary(ScrollingView::s_defaultZoomMode),
                winrt::PropertyChangedCallback(&OnZoomModePropertyChanged));
    }
}

void ScrollingViewProperties::ClearProperties()
{
    s_ComputedHorizontalScrollBarVisibilityProperty = nullptr;
    s_ComputedVerticalScrollBarVisibilityProperty = nullptr;
    s_ContentProperty = nullptr;
    s_ContentOrientationProperty = nullptr;
    s_HorizontalAnchorRatioProperty = nullptr;
    s_HorizontalScrollBarVisibilityProperty = nullptr;
    s_HorizontalScrollChainModeProperty = nullptr;
    s_HorizontalScrollControllerProperty = nullptr;
    s_HorizontalScrollModeProperty = nullptr;
    s_HorizontalScrollRailModeProperty = nullptr;
    s_IgnoredInputKindProperty = nullptr;
    s_MaxZoomFactorProperty = nullptr;
    s_MinZoomFactorProperty = nullptr;
    s_ScrollingPresenterProperty = nullptr;
    s_VerticalAnchorRatioProperty = nullptr;
    s_VerticalScrollBarVisibilityProperty = nullptr;
    s_VerticalScrollChainModeProperty = nullptr;
    s_VerticalScrollControllerProperty = nullptr;
    s_VerticalScrollModeProperty = nullptr;
    s_VerticalScrollRailModeProperty = nullptr;
    s_ZoomChainModeProperty = nullptr;
    s_ZoomModeProperty = nullptr;
}

void ScrollingViewProperties::OnComputedHorizontalScrollBarVisibilityPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnComputedVerticalScrollBarVisibilityPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnContentPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnContentOrientationPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnHorizontalAnchorRatioPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();

    auto value = winrt::unbox_value<double>(args.NewValue());
    auto coercedValue = value;
    winrt::get_self<ScrollingView>(owner)->ValidateAnchorRatio(coercedValue);
    if (std::memcmp(&value, &coercedValue, sizeof(value)) != 0) // use memcmp to avoid tripping over nan
    {
        sender.SetValue(args.Property(), winrt::box_value<double>(coercedValue));
        return;
    }

    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnHorizontalScrollBarVisibilityPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnHorizontalScrollChainModePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnHorizontalScrollControllerPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnHorizontalScrollModePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnHorizontalScrollRailModePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnIgnoredInputKindPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnMaxZoomFactorPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();

    auto value = winrt::unbox_value<double>(args.NewValue());
    auto coercedValue = value;
    winrt::get_self<ScrollingView>(owner)->ValidateZoomFactoryBoundary(coercedValue);
    if (std::memcmp(&value, &coercedValue, sizeof(value)) != 0) // use memcmp to avoid tripping over nan
    {
        sender.SetValue(args.Property(), winrt::box_value<double>(coercedValue));
        return;
    }

    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnMinZoomFactorPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();

    auto value = winrt::unbox_value<double>(args.NewValue());
    auto coercedValue = value;
    winrt::get_self<ScrollingView>(owner)->ValidateZoomFactoryBoundary(coercedValue);
    if (std::memcmp(&value, &coercedValue, sizeof(value)) != 0) // use memcmp to avoid tripping over nan
    {
        sender.SetValue(args.Property(), winrt::box_value<double>(coercedValue));
        return;
    }

    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnScrollingPresenterPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnVerticalAnchorRatioPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();

    auto value = winrt::unbox_value<double>(args.NewValue());
    auto coercedValue = value;
    winrt::get_self<ScrollingView>(owner)->ValidateAnchorRatio(coercedValue);
    if (std::memcmp(&value, &coercedValue, sizeof(value)) != 0) // use memcmp to avoid tripping over nan
    {
        sender.SetValue(args.Property(), winrt::box_value<double>(coercedValue));
        return;
    }

    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnVerticalScrollBarVisibilityPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnVerticalScrollChainModePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnVerticalScrollControllerPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnVerticalScrollModePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnVerticalScrollRailModePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnZoomChainModePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::OnZoomModePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ScrollingView>();
    winrt::get_self<ScrollingView>(owner)->OnPropertyChanged(args);
}

void ScrollingViewProperties::ComputedHorizontalScrollBarVisibility(winrt::Visibility const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_ComputedHorizontalScrollBarVisibilityProperty, ValueHelper<winrt::Visibility>::BoxValueIfNecessary(value));
}

winrt::Visibility ScrollingViewProperties::ComputedHorizontalScrollBarVisibility()
{
    return ValueHelper<winrt::Visibility>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_ComputedHorizontalScrollBarVisibilityProperty));
}

void ScrollingViewProperties::ComputedVerticalScrollBarVisibility(winrt::Visibility const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_ComputedVerticalScrollBarVisibilityProperty, ValueHelper<winrt::Visibility>::BoxValueIfNecessary(value));
}

winrt::Visibility ScrollingViewProperties::ComputedVerticalScrollBarVisibility()
{
    return ValueHelper<winrt::Visibility>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_ComputedVerticalScrollBarVisibilityProperty));
}

void ScrollingViewProperties::Content(winrt::UIElement const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_ContentProperty, ValueHelper<winrt::UIElement>::BoxValueIfNecessary(value));
}

winrt::UIElement ScrollingViewProperties::Content()
{
    return ValueHelper<winrt::UIElement>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_ContentProperty));
}

void ScrollingViewProperties::ContentOrientation(winrt::ScrollingContentOrientation const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_ContentOrientationProperty, ValueHelper<winrt::ScrollingContentOrientation>::BoxValueIfNecessary(value));
}

winrt::ScrollingContentOrientation ScrollingViewProperties::ContentOrientation()
{
    return ValueHelper<winrt::ScrollingContentOrientation>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_ContentOrientationProperty));
}

void ScrollingViewProperties::HorizontalAnchorRatio(double value)
{
    double coercedValue = value;
    static_cast<ScrollingView*>(this)->ValidateAnchorRatio(coercedValue);
    static_cast<ScrollingView*>(this)->SetValue(s_HorizontalAnchorRatioProperty, ValueHelper<double>::BoxValueIfNecessary(coercedValue));
}

double ScrollingViewProperties::HorizontalAnchorRatio()
{
    return ValueHelper<double>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_HorizontalAnchorRatioProperty));
}

void ScrollingViewProperties::HorizontalScrollBarVisibility(winrt::ScrollingScrollBarVisibility const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_HorizontalScrollBarVisibilityProperty, ValueHelper<winrt::ScrollingScrollBarVisibility>::BoxValueIfNecessary(value));
}

winrt::ScrollingScrollBarVisibility ScrollingViewProperties::HorizontalScrollBarVisibility()
{
    return ValueHelper<winrt::ScrollingScrollBarVisibility>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_HorizontalScrollBarVisibilityProperty));
}

void ScrollingViewProperties::HorizontalScrollChainMode(winrt::ScrollingChainMode const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_HorizontalScrollChainModeProperty, ValueHelper<winrt::ScrollingChainMode>::BoxValueIfNecessary(value));
}

winrt::ScrollingChainMode ScrollingViewProperties::HorizontalScrollChainMode()
{
    return ValueHelper<winrt::ScrollingChainMode>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_HorizontalScrollChainModeProperty));
}

void ScrollingViewProperties::HorizontalScrollController(winrt::IScrollController const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_HorizontalScrollControllerProperty, ValueHelper<winrt::IScrollController>::BoxValueIfNecessary(value));
}

winrt::IScrollController ScrollingViewProperties::HorizontalScrollController()
{
    return ValueHelper<winrt::IScrollController>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_HorizontalScrollControllerProperty));
}

void ScrollingViewProperties::HorizontalScrollMode(winrt::ScrollingScrollMode const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_HorizontalScrollModeProperty, ValueHelper<winrt::ScrollingScrollMode>::BoxValueIfNecessary(value));
}

winrt::ScrollingScrollMode ScrollingViewProperties::HorizontalScrollMode()
{
    return ValueHelper<winrt::ScrollingScrollMode>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_HorizontalScrollModeProperty));
}

void ScrollingViewProperties::HorizontalScrollRailMode(winrt::ScrollingRailMode const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_HorizontalScrollRailModeProperty, ValueHelper<winrt::ScrollingRailMode>::BoxValueIfNecessary(value));
}

winrt::ScrollingRailMode ScrollingViewProperties::HorizontalScrollRailMode()
{
    return ValueHelper<winrt::ScrollingRailMode>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_HorizontalScrollRailModeProperty));
}

void ScrollingViewProperties::IgnoredInputKind(winrt::ScrollingInputKinds const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_IgnoredInputKindProperty, ValueHelper<winrt::ScrollingInputKinds>::BoxValueIfNecessary(value));
}

winrt::ScrollingInputKinds ScrollingViewProperties::IgnoredInputKind()
{
    return ValueHelper<winrt::ScrollingInputKinds>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_IgnoredInputKindProperty));
}

void ScrollingViewProperties::MaxZoomFactor(double value)
{
    double coercedValue = value;
    static_cast<ScrollingView*>(this)->ValidateZoomFactoryBoundary(coercedValue);
    static_cast<ScrollingView*>(this)->SetValue(s_MaxZoomFactorProperty, ValueHelper<double>::BoxValueIfNecessary(coercedValue));
}

double ScrollingViewProperties::MaxZoomFactor()
{
    return ValueHelper<double>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_MaxZoomFactorProperty));
}

void ScrollingViewProperties::MinZoomFactor(double value)
{
    double coercedValue = value;
    static_cast<ScrollingView*>(this)->ValidateZoomFactoryBoundary(coercedValue);
    static_cast<ScrollingView*>(this)->SetValue(s_MinZoomFactorProperty, ValueHelper<double>::BoxValueIfNecessary(coercedValue));
}

double ScrollingViewProperties::MinZoomFactor()
{
    return ValueHelper<double>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_MinZoomFactorProperty));
}


void ScrollingViewProperties::VerticalAnchorRatio(double value)
{
    double coercedValue = value;
    static_cast<ScrollingView*>(this)->ValidateAnchorRatio(coercedValue);
    static_cast<ScrollingView*>(this)->SetValue(s_VerticalAnchorRatioProperty, ValueHelper<double>::BoxValueIfNecessary(coercedValue));
}

double ScrollingViewProperties::VerticalAnchorRatio()
{
    return ValueHelper<double>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_VerticalAnchorRatioProperty));
}

void ScrollingViewProperties::VerticalScrollBarVisibility(winrt::ScrollingScrollBarVisibility const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_VerticalScrollBarVisibilityProperty, ValueHelper<winrt::ScrollingScrollBarVisibility>::BoxValueIfNecessary(value));
}

winrt::ScrollingScrollBarVisibility ScrollingViewProperties::VerticalScrollBarVisibility()
{
    return ValueHelper<winrt::ScrollingScrollBarVisibility>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_VerticalScrollBarVisibilityProperty));
}

void ScrollingViewProperties::VerticalScrollChainMode(winrt::ScrollingChainMode const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_VerticalScrollChainModeProperty, ValueHelper<winrt::ScrollingChainMode>::BoxValueIfNecessary(value));
}

winrt::ScrollingChainMode ScrollingViewProperties::VerticalScrollChainMode()
{
    return ValueHelper<winrt::ScrollingChainMode>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_VerticalScrollChainModeProperty));
}

void ScrollingViewProperties::VerticalScrollController(winrt::IScrollController const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_VerticalScrollControllerProperty, ValueHelper<winrt::IScrollController>::BoxValueIfNecessary(value));
}

winrt::IScrollController ScrollingViewProperties::VerticalScrollController()
{
    return ValueHelper<winrt::IScrollController>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_VerticalScrollControllerProperty));
}

void ScrollingViewProperties::VerticalScrollMode(winrt::ScrollingScrollMode const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_VerticalScrollModeProperty, ValueHelper<winrt::ScrollingScrollMode>::BoxValueIfNecessary(value));
}

winrt::ScrollingScrollMode ScrollingViewProperties::VerticalScrollMode()
{
    return ValueHelper<winrt::ScrollingScrollMode>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_VerticalScrollModeProperty));
}

void ScrollingViewProperties::VerticalScrollRailMode(winrt::ScrollingRailMode const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_VerticalScrollRailModeProperty, ValueHelper<winrt::ScrollingRailMode>::BoxValueIfNecessary(value));
}

winrt::ScrollingRailMode ScrollingViewProperties::VerticalScrollRailMode()
{
    return ValueHelper<winrt::ScrollingRailMode>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_VerticalScrollRailModeProperty));
}

void ScrollingViewProperties::ZoomChainMode(winrt::ScrollingChainMode const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_ZoomChainModeProperty, ValueHelper<winrt::ScrollingChainMode>::BoxValueIfNecessary(value));
}

winrt::ScrollingChainMode ScrollingViewProperties::ZoomChainMode()
{
    return ValueHelper<winrt::ScrollingChainMode>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_ZoomChainModeProperty));
}

void ScrollingViewProperties::ZoomMode(winrt::ScrollingZoomMode const& value)
{
    static_cast<ScrollingView*>(this)->SetValue(s_ZoomModeProperty, ValueHelper<winrt::ScrollingZoomMode>::BoxValueIfNecessary(value));
}

winrt::ScrollingZoomMode ScrollingViewProperties::ZoomMode()
{
    return ValueHelper<winrt::ScrollingZoomMode>::CastOrUnbox(static_cast<ScrollingView*>(this)->GetValue(s_ZoomModeProperty));
}

winrt::event_token ScrollingViewProperties::AnchorRequested(winrt::TypedEventHandler<winrt::ScrollingView, winrt::ScrollingPresenterAnchorRequestedEventArgs> const& value)
{
    return m_anchorRequestedEventSource.add(value);
}

void ScrollingViewProperties::AnchorRequested(winrt::event_token const& token)
{
    m_anchorRequestedEventSource.remove(token);
}

winrt::event_token ScrollingViewProperties::BringingIntoView(winrt::TypedEventHandler<winrt::ScrollingView, winrt::ScrollingPresenterBringingIntoViewEventArgs> const& value)
{
    return m_bringingIntoViewEventSource.add(value);
}

void ScrollingViewProperties::BringingIntoView(winrt::event_token const& token)
{
    m_bringingIntoViewEventSource.remove(token);
}

winrt::event_token ScrollingViewProperties::ExtentChanged(winrt::TypedEventHandler<winrt::ScrollingView, winrt::IInspectable> const& value)
{
    return m_extentChangedEventSource.add(value);
}

void ScrollingViewProperties::ExtentChanged(winrt::event_token const& token)
{
    m_extentChangedEventSource.remove(token);
}

winrt::event_token ScrollingViewProperties::ScrollAnimationStarting(winrt::TypedEventHandler<winrt::ScrollingView, winrt::ScrollAnimationStartingEventArgs> const& value)
{
    return m_scrollAnimationStartingEventSource.add(value);
}

void ScrollingViewProperties::ScrollAnimationStarting(winrt::event_token const& token)
{
    m_scrollAnimationStartingEventSource.remove(token);
}

winrt::event_token ScrollingViewProperties::ScrollCompleted(winrt::TypedEventHandler<winrt::ScrollingView, winrt::ScrollCompletedEventArgs> const& value)
{
    return m_scrollCompletedEventSource.add(value);
}

void ScrollingViewProperties::ScrollCompleted(winrt::event_token const& token)
{
    m_scrollCompletedEventSource.remove(token);
}

winrt::event_token ScrollingViewProperties::StateChanged(winrt::TypedEventHandler<winrt::ScrollingView, winrt::IInspectable> const& value)
{
    return m_stateChangedEventSource.add(value);
}

void ScrollingViewProperties::StateChanged(winrt::event_token const& token)
{
    m_stateChangedEventSource.remove(token);
}

winrt::event_token ScrollingViewProperties::ViewChanged(winrt::TypedEventHandler<winrt::ScrollingView, winrt::IInspectable> const& value)
{
    return m_viewChangedEventSource.add(value);
}

void ScrollingViewProperties::ViewChanged(winrt::event_token const& token)
{
    m_viewChangedEventSource.remove(token);
}

winrt::event_token ScrollingViewProperties::ZoomAnimationStarting(winrt::TypedEventHandler<winrt::ScrollingView, winrt::ZoomAnimationStartingEventArgs> const& value)
{
    return m_zoomAnimationStartingEventSource.add(value);
}

void ScrollingViewProperties::ZoomAnimationStarting(winrt::event_token const& token)
{
    m_zoomAnimationStartingEventSource.remove(token);
}

winrt::event_token ScrollingViewProperties::ZoomCompleted(winrt::TypedEventHandler<winrt::ScrollingView, winrt::ZoomCompletedEventArgs> const& value)
{
    return m_zoomCompletedEventSource.add(value);
}

void ScrollingViewProperties::ZoomCompleted(winrt::event_token const& token)
{
    m_zoomCompletedEventSource.remove(token);
}