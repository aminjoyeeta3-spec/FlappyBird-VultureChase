#include "../../include/platform.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

#include <windows.h>
#include <conio.h>

#else

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#endif

void clearScreen(void)
{

#ifdef _WIN32

    system("cls");

#else

    system("clear");

#endif

}



void sleepMS(int milliseconds)
{

#ifdef _WIN32

    Sleep(milliseconds);

#else

    usleep(milliseconds * 1000);

#endif

}



int keyPressed(void)
{

#ifdef _WIN32

    return _kbhit();

#else

    return 0;

#endif

}



char getKey(void)
{

#ifdef _WIN32

    return _getch();

#else

    return 0;

#endif

}