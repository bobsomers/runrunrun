#include <ngn/app.h>
#include <ngn/hello.h>

//#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include <dlfcn.h>

// Global hookups to the game library.
void* gGameLib = nullptr;
ngn::App* gGameApp = nullptr;
ngn::CreateAppFunc* gCreateApp = nullptr;
ngn::DestroyAppFunc* gDestroyApp = nullptr;

void loadAndRunGame()
{
    if (gGameApp) {
        // Delete the game.
        gDestroyApp(gGameApp);
        gGameApp = nullptr;

        // Unload the library.
        dlclose(gGameLib);
        gGameLib = nullptr;
        gCreateApp = nullptr;
        gDestroyApp = nullptr;
    }

    // Open the game library.
    // TODO: use a cross platform wrapper to load the symbols, determine the
    // library names, and determine the path to the executable
    gGameLib = dlopen("install/libgame.dylib", RTLD_NOW);
    if (!gGameLib) {
        std::cerr << "Failed to open libgame: " << dlerror() << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // Reset errors.
    dlerror();

    // Yank out the app new and delete function symbols.
    gCreateApp = (ngn::CreateAppFunc*)(dlsym(gGameLib, "ngn_createApp"));
    const char* dlsymError = dlerror();
    if (dlsymError) {
        std::cerr << "Failed to load symbol 'ngn_createApp': " << dlsymError << std::endl;
        dlclose(gGameLib);
        std::exit(EXIT_FAILURE);
    }

    gDestroyApp = (ngn::DestroyAppFunc*)(dlsym(gGameLib, "ngn_destroyApp"));
    dlsymError = dlerror();
    if (dlsymError) {
        std::cerr << "Failed to load symbol 'ngn_destroyApp': " << dlsymError << std::endl;
        dlclose(gGameLib);
        std::exit(EXIT_FAILURE);
    }

    gGameApp = gCreateApp();
    gGameApp->run();
}

int main() {
    ngn::printHello("rrr");

    bool running = true;
    while (running) {
        std::string response;
        std::cout << "Press enter to load the game lib and run it (q to exit)." << std::endl;
        std::getline(std::cin, response);
        if (response == "q") {
            running = false;
            continue;
        }

        loadAndRunGame();
    }

//    if (!glfwInit()) {
//        std::cerr << "Failed to initialize GLFW." << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    GLFWwindow* window = glfwCreateWindow(640, 480, "Run? Run. Run!", nullptr, nullptr);
//    if (!window) {
//        std::cerr << "Failed to create window." << std::endl;
//        glfwTerminate();
//        return EXIT_FAILURE;
//    }
//
//    glfwMakeContextCurrent(window);
//
//    while (!glfwWindowShouldClose(window)) {
//        // TODO: render!
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
    return EXIT_SUCCESS;
}
