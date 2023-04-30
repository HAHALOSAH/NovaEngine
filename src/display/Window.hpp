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

#ifndef __WINDOW_HPP
#define __WINDOW_HPP

#include <string>

#include "XlibWindow.hpp"
#include "../Structs.hpp"

using std::string;

namespace nova
{
    class XlibWindow;
    class Window
    {
    public:
        explicit Window(string *title, struct Vector2 size);
        ~Window();
        void handleEvents();
        int width;
        int height;
        string *title;
    private:
        void initializeWindow();
#ifdef __linux__ // Enable Xlib window on linux
        XlibWindow *window;
#endif // __linux__
    };

}

#endif // __WINDOW_HPP