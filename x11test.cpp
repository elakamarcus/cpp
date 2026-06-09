#include <X11/Xlib.h>

int main(int argc, char** argv) {
    // Create a display and window
    Display* display = XOpenDisplay(NULL);
    Window window = XCreateSimpleWindow(display,
                                         0, 0, 800, 600,
                                         0, 0, 0, 0);

    // Set the window title
    XStoreName(display, window, "My Window");

    // Create a GC
    GC gc = XCreateGC(display, window, 0, 0);

    // Set the foreground color
    XSetForeground(display, gc, RGB(255, 0, 0));

    // Set the line width
    XSetLineWidth(display, gc, 2);

    // Set the line style
    XSetLineStyle(display, gc, LineSolid);

    // Set the cap style
    XSetCapStyle(display, gc, CapRound);

    // Set the fill style
    XSetFillStyle(display, gc, FillSolid);

    // Set the subwindow mode
    XSetSubwindowMode(display, window, ClipByChildren);

    // Set the clip origin
    XSetClipOrigin(display, window, 0, 0);

    // Set the clip mask
    XSetClipMask(display, window, None);

    // Draw a line between the two points
    XDrawLine(display, window, gc, 100, 100, 300, 300);

    // Show the window
    XMapRaised(display, window);

    // Process events
    XEvent event;
    while (XCheckWindowEvent(display, window, &event)) {
        if (event.type == Expose) {
            // Redraw the line
            XDrawLine(display, window, gc, 100, 100, 300, 300);
        }
    }

    // Clean up
    XDestroyGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0;
}
