#include <stdio.h>
#include <windows.h>
#include <time.h>
POINT point;
int main(int argc, char const *argv[])
{
    while (1)
    {
        if (GetAsyncKeyState(VK_F1))
        {
            break;
        }
        if (GetAsyncKeyState(VK_SHIFT))
        {

            // 点击左键5下
            SHORT last_status = GetAsyncKeyState(VK_LBUTTON);
            SHORT this_status = GetAsyncKeyState(VK_LBUTTON);
            if (this_status && (this_status != last_status))
            {
                time_t t;
                last_status = this_status;
                GetCursorPos(&point);
                for (int i = 0; i < 4; i++)
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, point.x, point.y, 0, 0);
                    mouse_event(MOUSEEVENTF_LEFTUP, point.x, point.y, 0, 0);
                }
            }

            // 点击右键5下
            SHORT last_status_r = GetAsyncKeyState(VK_RBUTTON);
            SHORT this_status_r = GetAsyncKeyState(VK_RBUTTON);
            if (this_status_r && (this_status_r != last_status_r))
            {
                time_t t;
                last_status_r = this_status_r;
                GetCursorPos(&point);
                for (int i = 0; i < 4; i++)
                {
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, point.x, point.y, 0, 0);
                    mouse_event(MOUSEEVENTF_RIGHTUP, point.x, point.y, 0, 0);
                }
            }
        }
    }
    return 0;
}
