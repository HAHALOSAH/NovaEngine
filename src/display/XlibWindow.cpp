#include <X11/Xlib.h>
#include <cstdlib>
#include <iostream>

#include "XlibWindow.hpp"

namespace nova
{
    XlibWindow::XlibWindow(string *title, Window *window)
    {
        this->window = window;
        this->title = title;
        this->initializeWindow();
    }

    XlibWindow::~XlibWindow()
    {
        delete this->title;
        free(this->display);
        if (this->xlibWindow != NULL)
        {
            delete this->xlibWindow;
        }
    }

    void XlibWindow::initializeWindow()
    {
        Display *display = XOpenDisplay(NULL);
        this->display = display;
        if (display == NULL)
        {
            exit(1);
        }
        int screen = DefaultScreen(display);
        ::Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0, this->window->width, this->window->height, 1, BlackPixel(display, screen), WhitePixel(display, screen));
        this->xlibWindow = new ::Window(window);
        XSelectInput(display, window, ExposureMask | KeyPressMask | StructureNotifyMask);
        XStoreName(display, window, this->title->c_str());
        XMapWindow(display, window);
        XFlush(display);

        XWindowAttributes window_attributes;
        XGetWindowAttributes(display, window, &window_attributes);

        // XEvent event;
        // XNextEvent(display, &event);

        // this->image = XGetImage(display, window, 0, 0, window_attributes.width, window_attributes.height, AllPlanes, ZPixmap);
    }
    void XlibWindow::handleEvents()
    {
        /*XEvent event;
        XNextEvent(this->display, &event);
        switch (event.type)
        {
        case Expose:
            if (event.xexpose.count != 0)
            {
                break;
            }
            XWindowAttributes window_attributes;
            XGetWindowAttributes(display, *xlibWindow, &window_attributes);
            //this->image = XGetImage(display, *xlibWindow, 0, 0, window_attributes.width, window_attributes.height, AllPlanes, ZPixmap);
            break;
        case KeyPress:
            break;
        }*/
    }
} // namespace nova