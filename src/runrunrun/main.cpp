//#include "rrrgame/lib.h"

#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>
//#include <string>

//#include <dlfcn.h>

// Global hookups to the game library.
//void* gGameLib = nullptr;
//rrr::App* gGameApp = nullptr;
//rrr_NewAppFunc gNewApp = nullptr;
//rrr_DeleteAppFunc gDeleteApp = nullptr;

//static void errorCallback(int error, const char* description);

//void loadGameLib()
//{
//    // Close the old game library if already opened.
//    if (gGameApp) {
//        gDeleteApp(gGameApp);
//        gGameApp = nullptr;
//        gNewApp = nullptr;
//        gDeleteApp = nullptr;
//        dlclose(gGameLib);
//        dlclose(gGameLib); // TODO: WTF
//        std::cout << "dlclose!" << std::endl;
//        gGameLib = nullptr;
//    }
//
//    // Open the game library.
//    gGameLib = dlopen("./librrrgame.dylib", RTLD_NOW);
//    std::cout << "dlopen!" << std::endl;
//    if (!gGameLib) {
//        std::cerr << "Failed to open librrrgame: " << dlerror() << std::endl;
//        std::exit(EXIT_FAILURE);
//    }
//
//    // Reset errors.
//    dlerror();
//
//    // Yank out the app new and delete function symbols.
//    gNewApp = (rrr_NewAppFunc)(dlsym(gGameLib, "rrr_newApp"));
//    const char* dlsymError = dlerror();
//    if (dlsymError) {
//        std::cerr << "Failed to load symbol 'rrr_newApp': " << dlsymError << std::endl;
//        dlclose(gGameLib);
//        std::cout << "dlclose!" << std::endl;
//        std::exit(EXIT_FAILURE);
//    }
//
//    gDeleteApp = (rrr_DeleteAppFunc)(dlsym(gGameLib, "rrr_deleteApp"));
//    dlsymError = dlerror();
//    if (dlsymError) {
//        std::cerr << "Failed to load symbol 'rrr_deleteApp': " << dlsymError << std::endl;
//        dlclose(gGameLib);
//        std::cout << "dlclose!" << std::endl;
//        std::exit(EXIT_FAILURE);
//    }
//}

int main() {
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
//        gGameApp = gNewApp();
//        gGameApp->run();
//    }

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return EXIT_FAILURE;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Run? Run. Run!", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window." << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        // TODO: render!

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}
