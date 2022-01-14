// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimpleMenuBarBuilder.h"
#include "Modules/ModuleManager.h"
#include "NativeWidgetHostMenuBar.h"

class FMenuBarBuilderTestModule : public FDefaultGameModuleImpl {
public:
	virtual void StartupModule() override {
		FTestMenuCommands::Register();
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE( FMenuBarBuilderTestModule, SimpleMenuBarBuilder, "SimpleMenuBarBuilder" );
