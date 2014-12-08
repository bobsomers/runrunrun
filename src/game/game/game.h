#pragma once

#include "app.h"

typedef rrr::App* (*rrr_NewAppFunc)();
typedef void (*rrr_DeleteAppFunc)(rrr::App* app);

extern "C" rrr::App* rrr_newApp();
extern "C" void rrr_deleteApp(rrr::App* app);
