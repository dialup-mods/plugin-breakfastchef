#pragma once
#include "IToaster.h"
#include "SDK.h"
#include "v1/ILogger.h"
#include "v1/IResolver.h"
#include "v1/IPlugin.h"
#include "v1/PluginBase.h"

class BreakfastChef : public PluginBase<BreakfastChef> {
    ~BreakfastChef() override = default;
    auto getName() const -> const char* override { return "BreakfastChef"; }

    void startup() override {
        printf("BreakfastChef::startup() called\n");
        setPluginReady();
        printf("BreakfastChef: resolving IToaster\n");
        auto toaster = resolve<IToaster>();
        if (toaster) {
            printf("\n\nBeware, bread! BreakfastChef is preparing toast!\n");
            toaster->toast(L"Welcome.", L"You've got mail!");
        } else {
            printf("BreakfastChef: failed to resolve IToaster!\n");
        }
    }

    void shutdown() override {
        setPluginYeetable();
    }

    auto registerPublicInterfaces() const -> std::vector<PublicInterface> override { return {}; }
};