#include "game_app.h"

#include <ngn/app.h>

#include <iostream>

namespace game {

void GameApp::run()
{
    std::cout << "game::GameApp::run()" << std::endl;
}

} // namespace game

extern "C" ngn::App* ngn_createApp()
{
    return new game::GameApp;
}

extern "C" void ngn_destroyApp(ngn::App* app)
{
    delete app;
}
