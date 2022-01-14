// Fill out your copyright notice in the Description page of Project Settings.


#include "NativeWidgetHostMenuBar.h"

TSharedRef<SWidget> UNativeWidgetHostMenuBar::RebuildWidget() {
  FMenuBarBuilder MenuBarBuilder(CommandList);
  MenuBarBuilder.SetStyle(&FCoreStyle::Get(), "Menu");

  MenuBarBuilder.AddPullDownMenu
  (
    FText::FromString("TestMenu"), // menu label
    FText::FromString("This is TestMenu."), // tool tip
    FNewMenuDelegate::CreateLambda([](FMenuBuilder& MenuBuilder)
      {
        //MenuA
        MenuBuilder.AddMenuEntry(FTestMenuCommands::Get().MenuA);
        
        //MenuB
        MenuBuilder.AddSubMenu
        (
          FText::FromString("MenuB"),
          FText::FromString("This is MenuB"),
          FNewMenuDelegate::CreateLambda([](FMenuBuilder& SubMenuBuilder)
            {
              SubMenuBuilder.AddMenuEntry(FTestMenuCommands::Get().MenuB_1);
              SubMenuBuilder.AddMenuEntry(FTestMenuCommands::Get().MenuB_2);
              SubMenuBuilder.AddMenuEntry(FTestMenuCommands::Get().MenuB_3);
            }
          )
        );

        //MenuC
        MenuBuilder.AddSubMenu
        (
          FText::FromString("MenuC"),
          FText::FromString("This is MenuC"),
          FNewMenuDelegate::CreateLambda([](FMenuBuilder& SubMenuBuilder)
            {
              SubMenuBuilder.AddMenuEntry(FTestMenuCommands::Get().MenuC_1);

              //MenuC_2
              SubMenuBuilder.AddSubMenu
              (
                FText::FromString("MenuC_2"),
                FText::FromString("This is MenuC_2"),
                FNewMenuDelegate::CreateLambda([](FMenuBuilder& SubSubMenuBuilder)
                  {
                    SubSubMenuBuilder.AddMenuEntry(FTestMenuCommands::Get().MenuC_2_1);
                    SubSubMenuBuilder.AddMenuEntry(FTestMenuCommands::Get().MenuC_2_2);
                  }
                )
              );
            }
          )
        );
      }
    )
  );

  SetContent(MenuBarBuilder.MakeWidget());
  return SNew(SBox)
    [
      NativeWidget.ToSharedRef()
    ];
}

TSharedRef<FUICommandList> UNativeWidgetHostMenuBar::CommandList = MakeShared<FUICommandList>();