#pragma once

namespace rrr {

class App
{
public:
    App();

    void run();

    // Callbacks from GLFW.
    void error(int error, const char* description);
};

} // namespace rrr
