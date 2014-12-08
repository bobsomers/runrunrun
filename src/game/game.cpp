#include "game/game.h"

extern "C" rrr::App* rrr_newApp()
{
    return new rrr::App;
}

extern "C" void rrr_deleteApp(rrr::App* app)
{
    delete app;
}
