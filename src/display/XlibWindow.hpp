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