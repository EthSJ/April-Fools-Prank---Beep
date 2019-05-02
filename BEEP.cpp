#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <MMSystem.h>
#include <iostream>
#include <time.h>
#include <chrono>

int main(int argc, char* argv[])
{

    //Does all the work to hide the console + preserve name.
    HWND hWnd = ::GetConsoleWindow();
    long style= GetWindowLong(hWnd, GWL_STYLE);
    style &= ~(WS_VISIBLE);    // this works - window become invisible

    style |= WS_EX_TOOLWINDOW;   // flags don't work - windows remains in taskbar
    style &= ~(WS_EX_APPWINDOW);

    ShowWindow(hWnd, SW_HIDE); // hide the window
    SetWindowLong(hWnd, GWL_STYLE, style); // set the style
    ShowWindow(hWnd, SW_SHOW); // show the window for the new style to come into effect
    ShowWindow(hWnd, SW_HIDE); // hide the window so we can't see it

    //setup stuff
    srand(time(NULL));
    int timer= 10, stop=0, switchSpot;
    switchSpot = rand()%timer + 1;

    //main loop. time in hours * hour multiplier
    while(stop <= 5*60)
    {
        //Play sound
        //randomize a new time
        //set it to be switchspot
        //add the time to that (in minutes), and loop again
        PlaySound(TEXT("C:\\Program Files (x86)\\Steam\\friends\\message.wav"), NULL, SND_ASYNC);
        switchSpot = rand()%timer + 1;
        stop += switchSpot;
        Sleep(switchSpot*60000);
    }
    return 0;
}


