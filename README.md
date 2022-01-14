# SimpleMenuBarBuilder

Unreal Engine 4.26, Windows 10, Visual Studio 2019

I would like to use FMenuBarBuilder inside my application, and tried using UNativeWidgetHost to use the menu as a component of UMG.
It was not so difficult to use FMenuBarBuilder through UNativeWidgetHost.
The problem is that the menu is not rendered correctly.

![Desktop 2022-01-14 - 09-58-04-06_1](https://user-images.githubusercontent.com/8625552/149435370-82b9600b-1e92-4713-a5ab-2308a171aeb2.gif)

Whenever the mouse cursor is moved to submenu, the owner’s hovered status seems to be removed. For example, when the mouse cursor is on “MenuB_1”, the background of “MenuB” should be kept orange, and the font color of “TestMenu” should be white. Both should be kept as the hovered status.

And when I click “MenuB”, the submenu disappears and appears, while it should not be disappeared.

The editor’s menu is of course rendered correctly, so it might not be a bug, but the side effect of using UNativeWidgetHost.

I found that the status of the owner of the submenu is decided by
SMenuEntryBlock::ShouldSubMenuAppearHovered of SMenuEntryBlock.cpp
and
the status of

```
!OwnerMultiBoxWidget.Pin()->IsHovered()
```

is inversed whenever using FMenuBarBuilder through UNativeWidgetHost.
So maybe OwnerMultiBoxWidget is not set correctly when using FMenuBarBuilder inside UNativeWidgetHost.
If I remove "!" and modified the function to
```
bool SMenuEntryBlock::ShouldSubMenuAppearHovered() const
{
	// The sub-menu entry should appear hovered if the sub-menu is open.  Except in the case that the user is actually interacting with this menu.  
	// In that case we need to show what the user is selecting
	return MenuAnchor.IsValid() && MenuAnchor.Pin()->IsOpen() && OwnerMultiBoxWidget.Pin()->IsHovered();
}
```

Then the menu is rendered correctly.
(The problem of disappearance of the submenu by clicking the owner still remains.)

I've upload whole the project code to GitHub.
[https://github.com/HSeo/SimpleMenuBarBuilder](https://github.com/HSeo/SimpleMenuBarBuilder)

Any comment would be very welcome.
Thank you.


![FMenuBarBuilderUMGTest](https://user-images.githubusercontent.com/8625552/149435416-cc786af9-a816-4e97-8a6b-69c8eef86fa2.jpg)
