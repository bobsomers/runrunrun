#include <ngn/hello.h>
//#include <ngn/app.h>

//#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>
#include <string>

//#include <dlfcn.h>
//
//// Global hookups to the game library.
//void* gGameLib = nullptr;
//App* gGameApp = nullptr;
//CreateAppFunc* gCreateApp = nullptr;
//DestroyAppFunc* gDestroyApp = nullptr;
//
////static void errorCallback(int error, const char* description);
//
//void loadGameLib()
//{
//    // Close the old game library if already opened.
//    if (gGameApp) {
//        gDestroyApp(gGameApp);
//        gGameApp = nullptr;
//        gCreateApp = nullptr;
//        gDestroyApp = nullptr;
//        dlclose(gGameLib);
//        std::cout << "dlclose!" << std::endl;
//        gGameLib = nullptr;
//    }
//
//    // Open the game library.
//    gGameLib = dlopen("install/libgame.dylib", RTLD_NOW);
//    std::cout << "dlopen!" << std::endl;
//    if (!gGameLib) {
//        std::cerr << "Failed to open libgame: " << dlerror() << std::endl;
//        std::exit(EXIT_FAILURE);
//    }
//
//    // Reset errors.
//    dlerror();
//
//    // Yank out the app new and delete function symbols.
//    gCreateApp = (CreateAppFunc*)(dlsym(gGameLib, "rrr_createApp"));
//    const char* dlsymError = dlerror();
//    if (dlsymError) {
//        std::cerr << "Failed to load symbol 'rrr_createApp': " << dlsymError << std::endl;
//        dlclose(gGameLib);
//        std::cout << "dlclose!" << std::endl;
//        std::exit(EXIT_FAILURE);
//    }
//
//    gDestroyApp = (DestroyAppFunc*)(dlsym(gGameLib, "rrr_destroyApp"));
//    dlsymError = dlerror();
//    if (dlsymError) {
//        std::cerr << "Failed to load symbol 'rrr_destroyApp': " << dlsymError << std::endl;
//        dlclose(gGameLib);
//        std::cout << "dlclose!" << std::endl;
//        std::exit(EXIT_FAILURE);
//    }
//}

int main() {
    ngn::printHello("rrr");
//    bool running = true;
//    while (running) {
//        std::string response;
//        std::cout << "Press enter to load the game lib and run it (q to exit)." << std::endl;
//        std::getline(std::cin, response);
//        if (response == "q") {
//            running = false;
//            continue;
//        }
//
//        loadGameLib();
//        gGameApp = gCreateApp();
//        gGameApp->run();
//    }

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
