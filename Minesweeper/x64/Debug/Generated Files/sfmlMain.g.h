// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220531.1

#pragma once
#include "winrt/Minesweeper.h"
#include "winrt/Windows.UI.Composition.h"
#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Controls.h"
namespace winrt::Minesweeper::implementation
{
    template <typename D, typename... I>
    struct __declspec(empty_bases) sfmlMain_base : implements<D, Minesweeper::sfmlMain, composing, winrt::Windows::UI::Xaml::Controls::IPageOverrides, winrt::Windows::UI::Xaml::Controls::IControlOverrides, winrt::Windows::UI::Xaml::Controls::IControlOverrides6, winrt::Windows::UI::Xaml::IFrameworkElementOverrides, winrt::Windows::UI::Xaml::IFrameworkElementOverrides2, winrt::Windows::UI::Xaml::IUIElementOverrides, winrt::Windows::UI::Xaml::IUIElementOverrides7, winrt::Windows::UI::Xaml::IUIElementOverrides8, winrt::Windows::UI::Xaml::IUIElementOverrides9, I...>,
        impl::require<D, winrt::Windows::UI::Xaml::Controls::IPage, winrt::Windows::UI::Xaml::Controls::IUserControl, winrt::Windows::UI::Xaml::Controls::IControl, winrt::Windows::UI::Xaml::Controls::IControl2, winrt::Windows::UI::Xaml::Controls::IControl3, winrt::Windows::UI::Xaml::Controls::IControl4, winrt::Windows::UI::Xaml::Controls::IControl5, winrt::Windows::UI::Xaml::Controls::IControl7, winrt::Windows::UI::Xaml::Controls::IControlProtected, winrt::Windows::UI::Xaml::IFrameworkElement, winrt::Windows::UI::Xaml::IFrameworkElement2, winrt::Windows::UI::Xaml::IFrameworkElement3, winrt::Windows::UI::Xaml::IFrameworkElement4, winrt::Windows::UI::Xaml::IFrameworkElement6, winrt::Windows::UI::Xaml::IFrameworkElement7, winrt::Windows::UI::Xaml::IFrameworkElementProtected7, winrt::Windows::UI::Xaml::IUIElement, winrt::Windows::UI::Xaml::IUIElement2, winrt::Windows::UI::Xaml::IUIElement3, winrt::Windows::UI::Xaml::IUIElement4, winrt::Windows::UI::Xaml::IUIElement5, winrt::Windows::UI::Xaml::IUIElement7, winrt::Windows::UI::Xaml::IUIElement8, winrt::Windows::UI::Xaml::IUIElement9, winrt::Windows::UI::Xaml::IUIElement10, winrt::Windows::UI::Composition::IAnimationObject, winrt::Windows::UI::Composition::IVisualElement, winrt::Windows::UI::Xaml::IDependencyObject, winrt::Windows::UI::Xaml::IDependencyObject2>,
        impl::base<D, winrt::Windows::UI::Xaml::Controls::Page, winrt::Windows::UI::Xaml::Controls::UserControl, winrt::Windows::UI::Xaml::Controls::Control, winrt::Windows::UI::Xaml::FrameworkElement, winrt::Windows::UI::Xaml::UIElement, winrt::Windows::UI::Xaml::DependencyObject>,
        winrt::Windows::UI::Xaml::Controls::IPageOverridesT<D>, winrt::Windows::UI::Xaml::Controls::IControlOverridesT<D>, winrt::Windows::UI::Xaml::Controls::IControlOverrides6T<D>, winrt::Windows::UI::Xaml::IFrameworkElementOverridesT<D>, winrt::Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, winrt::Windows::UI::Xaml::IUIElementOverridesT<D>, winrt::Windows::UI::Xaml::IUIElementOverrides7T<D>, winrt::Windows::UI::Xaml::IUIElementOverrides8T<D>, winrt::Windows::UI::Xaml::IUIElementOverrides9T<D>
    {
        using base_type = sfmlMain_base;
        using class_type = Minesweeper::sfmlMain;
        using implements_type = typename sfmlMain_base::implements_type;
        using implements_type::implements_type;
        using composable_base = winrt::Windows::UI::Xaml::Controls::Page;
        hstring GetRuntimeClassName() const
        {
            return L"Minesweeper.sfmlMain";
        }
        sfmlMain_base()
        {
            impl::call_factory<winrt::Windows::UI::Xaml::Controls::Page, winrt::Windows::UI::Xaml::Controls::IPageFactory>([&](winrt::Windows::UI::Xaml::Controls::IPageFactory const& f) { [[maybe_unused]] auto winrt_impl_discarded = f.CreateInstance(*this, this->m_inner); });
        }
    };
}
namespace winrt::Minesweeper::factory_implementation
{
    template <typename D, typename T, typename... I>
    struct __declspec(empty_bases) sfmlMainT : implements<D, winrt::Windows::Foundation::IActivationFactory, I...>
    {
        using instance_type = Minesweeper::sfmlMain;

        hstring GetRuntimeClassName() const
        {
            return L"Minesweeper.sfmlMain";
        }
        auto ActivateInstance() const
        {
            return make<T>();
        }
    };
}

#if defined(WINRT_FORCE_INCLUDE_SFMLMAIN_XAML_G_H) || __has_include("sfmlMain.xaml.g.h")

#include "sfmlMain.xaml.g.h"

#else

namespace winrt::Minesweeper::implementation
{
    template <typename D, typename... I>
    using sfmlMainT = sfmlMain_base<D, I...>;
}

#endif
