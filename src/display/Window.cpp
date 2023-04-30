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

#include "Window.hpp"

#include "../Structs.hpp"

namespace nova
{
    Window::Window(string *title, struct Vector2 size)
    {
        this->width = size.x;
        this->height = size.y;
        this->title = title;
        this->initializeWindow();
    };

    Window::~Window()
    {
        delete this->title;
    }

    void Window::initializeWindow()
    {
#ifdef __linux__ // Enable Xlib display on linux
        this->window = new XlibWindow(this->title, this);
#endif           // __linux__
    }

    void Window::handleEvents()
    {
#ifdef __linux__
        this->window->handleEvents();
#endif           // __linux__
    }
} // namespace nova