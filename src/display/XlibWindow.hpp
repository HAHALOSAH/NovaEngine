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

#ifdef __linux__ // Enable Xlib wiwndow on linux
#ifndef __XLIBWINDOW_HPP
#define __XLIBWINDOW_HPP

#include <string>
#include <X11/Xlib.h>

#include "Window.hpp"
#include "../Structs.hpp"

using std::string;

namespace nova
{
    class Window;
    class XlibWindow
    {
    public:
        explicit XlibWindow(string *title, nova::Window *window);
        ~XlibWindow();
        void handleEvents();
        string *title;
    private:
        XImage *image;
        Window *window;
        ::Display *display;
        ::Window *xlibWindow;
        void initializeWindow();
    };
}

#endif // __XLIBWINDOW_HPP
#endif // __linux__