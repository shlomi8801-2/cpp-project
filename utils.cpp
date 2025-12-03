#ifndef utils
#define utils

#include "console.h"
#include <ctime>

using std::cout, std::flush, std::time;
void DrawAt(int x, int y, char c)
{
    gotoxy(x, y);
    cout << c << std::flush;
}
int getfps()
{
    // counts the times run before last check and devide the times run by the delta of time in seconds to get fps
    static int lasttime = 0;
    static long loops = 0;
    static int lastfps = 0;
    int curr = std::time(nullptr);
    if (lasttime == 0)
    {
        lasttime = curr;
    }
    else if (lasttime == curr)
    {
        loops++;
    }
    else
    {
        lastfps = loops / (curr - lasttime);
        loops = 0;
        lasttime = curr;
    }
    return lastfps;
}
void showfps()
{
    // run every frame in the loop or just the getfps() and only when you want to show the fps
    // dont use without delay!!!(printing to screen is much slower so it just prints nonstop)
    const int x = 0, y = 0, width = 10;
    gotoxy(x, y);

    for (int i = 0; i < width; i++)
    {
        std::cout << ' ';
    }
    gotoxy(x, y);
    std::cout << getfps() << std::flush;
}

#endif