#ifndef __NOVA_HPP
#define __NOVA_HPP

#include "display/Window.hpp"

namespace nova {
    class Window;
    class Nova {
        public:
            Nova(string* title, struct Vector2 size);
            ~Nova();
            void joinMainThread();
            Window *window;
        private:
            #if defined(__linux__) || defined(__APPLE__) // Use pthread on linux and macos
            pthread_t thread;
            #elif defined(_WIN32) || defined(_WIN64) // Use windows threads on windows
            HANDLE thread;
            #endif // __linux__ || __APPLE__
    };
}

#endif // __NOVA_HPP