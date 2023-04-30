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