#include "game_app.h"

#include <runrunrun/app.h>

#include <iostream>

namespace rrr {

void GameApp::run()
{
    std::cout << "GameApp::run()" << std::endl;
}

} // namespace rrr

extern "C" App* rrr_createApp()
{
    return new rrr::GameApp;
}

extern "C" void rrr_destroyApp(App* app)
{
    delete app;
}
