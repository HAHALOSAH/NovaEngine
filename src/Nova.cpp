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