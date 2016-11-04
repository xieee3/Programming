//
// Platform : Windows
//
// Read characters without echo on the screen.
//
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define StringLength 6

//***
// Because getch() is not a standard function. getch is replaced by _getch.
// A workaround function ReadCharWithoutEcho() has the same ability with getch.
//***
TCHAR ReadCharWithoutEcho() {
    DWORD mode, cc;
    HANDLE h = GetStdHandle( STD_INPUT_HANDLE );
    if (h == NULL) {
        return 0; // console not found
    }
    GetConsoleMode( h, &mode );
    SetConsoleMode( h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT) );
    TCHAR c = 0;
    ReadConsole( h, &c, 1, &cc, NULL );
    SetConsoleMode( h, mode );
    return c;
}

int main()
{
    int Count;
    char Ptr[StringLength];
    Count = 0;
    Ptr[Count] = ReadCharWithoutEcho();
    while (Count < StringLength)
    {
        Ptr[Count] = getchar();
        if (Ptr[Count] == '0' || Ptr[Count] == '1')
        {
            Count++;
        }

        if (Ptr[Count] == '\r' || Ptr[Count] == '\n')
            break;
    }
    Ptr[Count] = '\0';
    printf("\n%s %d", Ptr, strlen(Ptr));
    return 0;
}
