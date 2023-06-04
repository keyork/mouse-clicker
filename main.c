#include <stdio.h>
#include <windows.h>
POINT point;

int main(int argc, char const *argv[])
{
    system("chcp 65001");
    printf("红色警戒2鼠标连点器\n");
    int click_times = 5;
    while (1)
    {
        SHORT f1_p = GetAsyncKeyState(VK_F1);
        SHORT f1 = GetAsyncKeyState(VK_F1);
        SHORT f2_p = GetAsyncKeyState(VK_F2);
        SHORT f2 = GetAsyncKeyState(VK_F2);
        SHORT f3_p = GetAsyncKeyState(VK_F3);
        SHORT f3 = GetAsyncKeyState(VK_F3);
        SHORT f4_p = GetAsyncKeyState(VK_F4);
        SHORT f4 = GetAsyncKeyState(VK_F4);

        // 按住A之后就QWER轮着按，刷APM用
        SHORT f_a = GetAsyncKeyState(65);
        SHORT f_ap = GetAsyncKeyState(65);
        if (f_a && (f_a != f_ap))
        {
            keybd_event(81, 0, 0, 0);
            keybd_event(81, 0, 2, 0);
            keybd_event(87, 0, 0, 0);
            keybd_event(87, 0, 2, 0);
            keybd_event(69, 0, 0, 0);
            keybd_event(69, 0, 2, 0);
            keybd_event(82, 0, 0, 0);
            keybd_event(82, 0, 2, 0);
            f_ap = f_a;
        }

        if (GetAsyncKeyState(VK_F5))
        {
            printf("退出\n");
            break;
        }
        if (f1 && (f1 != f1_p))
        {
            click_times = 5;
            printf("[切换]连点次数: %d\n", click_times);
            f1_p = f1;
        }
        if (f2 && (f2 != f2_p))
        {
            click_times = 10;
            printf("[切换]连点次数: %d\n", click_times);
            f2_p = f2;
        }
        if (f3 && (f3 != f3_p))
        {
            click_times = 30;
            printf("[切换]连点次数: %d\n", click_times);
            f3_p = f3;
        }
        if (f4 && (f4 != f4_p))
        {
            click_times = 100;
            printf("[切换]连点次数: %d\n", click_times);
            f4_p = f4;
        }
        if (GetAsyncKeyState(VK_SHIFT))
        {

            // 点击左键5下
            SHORT last_status = GetAsyncKeyState(VK_LBUTTON);
            SHORT this_status = GetAsyncKeyState(VK_LBUTTON);
            if (this_status && (this_status != last_status))
            {
                last_status = this_status;
                GetCursorPos(&point);
                for (int i = 0; i < click_times - 1; i++)
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
                last_status_r = this_status_r;
                GetCursorPos(&point);
                for (int i = 0; i < click_times - 1; i++)
                {
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, point.x, point.y, 0, 0);
                    mouse_event(MOUSEEVENTF_RIGHTUP, point.x, point.y, 0, 0);
                }
            }
        }
    }
    return 0;
}
