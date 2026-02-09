#include "BreakfastChef.h"

extern "C" __declspec(dllexport) void*
create() {
    printf("load() called\n");
    return new BreakfastChef();
}

extern "C" __declspec(dllexport) void
destroy() {}
