#pragma once

// Exported headers. Anyone who includes "rrrgame/lib.h" will pick these up.
#include "rrrgame/app.h"

extern "C" {

typedef rrr::App* (*rrr_NewAppFunc)();
rrr::App* rrr_newApp();

typedef void (*rrr_DeleteAppFunc)(rrr::App* app);
void rrr_deleteApp(rrr::App* app);

} // extern "C"
