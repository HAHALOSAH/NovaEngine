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

#include "Nova.hpp"
#include "Threads.hpp"

namespace nova {
    void *novaMainThread(void *ptr);
    Nova::Nova(string* title, struct Vector2 size) {
        this->window = new Window(title, size);
        this->thread = createThread(novaMainThread, this);
    }
    Nova::~Nova() {
        delete this->window;
    }
    void Nova::joinMainThread() {
        joinThread(this->thread);
    }
    void *novaMainThread(void *ptr) {
        while (true) {
            ((Nova*)ptr)->window->handleEvents();
        }
    }
} // namespace nova