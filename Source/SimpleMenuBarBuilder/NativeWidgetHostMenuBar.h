// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/NativeWidgetHost.h"
#include "Framework/Commands/Commands.h"
#include "NativeWidgetHostMenuBar.generated.h"

#define LOCTEXT_NAMESPACE "TestMenuCommands"

class FTestMenuCommands : public TCommands<FTestMenuCommands> {
public:
  FTestMenuCommands() : TCommands<FTestMenuCommands>(
    TEXT("TestMenuCommands"), // Context name for fast lookup
    LOCTEXT("TestMenuCommands", "test menu commands"), // Context name for displaying
    NAME_None, // No parent context
    FCoreStyle::Get().GetStyleSetName()) {};

  TSharedPtr<class FUICommandInfo> MenuA;

  TSharedPtr<class FUICommandInfo> MenuB;
  TSharedPtr<class FUICommandInfo> MenuB_1;
  TSharedPtr<class FUICommandInfo> MenuB_2;
  TSharedPtr<class FUICommandInfo> MenuB_3;

  TSharedPtr<class FUICommandInfo> MenuC;
  TSharedPtr<class FUICommandInfo> MenuC_1;
  TSharedPtr<class FUICommandInfo> MenuC_2;
  TSharedPtr<class FUICommandInfo> MenuC_2_1;
  TSharedPtr<class FUICommandInfo> MenuC_2_2;

  virtual void RegisterCommands() override
  {
    UI_COMMAND(MenuA, "MenuA", "This is MenuA.", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::A));

    // MenuB
    UI_COMMAND(MenuB_1, "MenuB_1", "This is MenuB_1.", EUserInterfaceActionType::Button, FInputChord());
    UI_COMMAND(MenuB_2, "MenuB_2", "This is MenuB_2.", EUserInterfaceActionType::Button, FInputChord());
    UI_COMMAND(MenuB_3, "MenuB_3", "This is MenuB_3.", EUserInterfaceActionType::Button, FInputChord());

    // MenuC
    UI_COMMAND(MenuC_1, "MenuC_1", "This is MenuC_1.", EUserInterfaceActionType::Button, FInputChord());
    //MenuC_2
    UI_COMMAND(MenuC_2_1, "MenuC_2_1", "This is MenuC_2_1.", EUserInterfaceActionType::Button, FInputChord());
    UI_COMMAND(MenuC_2_2, "MenuC_2_2", "This is MenuC_2_2.", EUserInterfaceActionType::Button, FInputChord());
  }
};

#undef LOCTEXT_NAMESPACE

UCLASS()
class SIMPLEMENUBARBUILDER_API UNativeWidgetHostMenuBar : public UNativeWidgetHost
{
	GENERATED_BODY()
public:
  virtual TSharedRef<SWidget> RebuildWidget() override;

private:
  static TSharedRef<FUICommandList> CommandList;
};
