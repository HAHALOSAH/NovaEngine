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