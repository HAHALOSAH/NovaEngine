/**
 * This file is part of the Nova game engine.
 * Copyright (c) 2023 HAHALOSAH
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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