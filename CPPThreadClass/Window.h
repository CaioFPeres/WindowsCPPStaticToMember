#include <windows.h>


template<class T> class Window {

public:

    Window() {
        SetWindowLongPtrA(hwnd, 0, (LONG_PTR)this);
    }

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        Window* me = reinterpret_cast<Simple*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        if (me) return me->realWndProc(hwnd, msg, wParam, lParam);
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

private:

    HWND hwnd;

    LRESULT CALLBACK realWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        // member function!
    }

};
