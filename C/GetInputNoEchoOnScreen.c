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
#define Base 2

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
    int StrLength;
    int Sum;
    int Value;
    int ShiftOffset;
    char Ptr[StringLength];
    Sum = 0;
    Value = 0;
    Count = 0;
    ShiftOffset = 0;
    //Ptr[Count] = ReadCharWithoutEcho();
    while (Count < StringLength)
    {
        Ptr[Count] = ReadCharWithoutEcho();
        if (Ptr[Count] == '0' || Ptr[Count] == '1')
        {
            printf("%c", Ptr[Count]);
            Count++;
        }

        if (Ptr[Count] == '\r' || Ptr[Count] == '\n')
            break;
    }
    Ptr[Count] = '\0';
    StrLength = strlen(Ptr);
    for (Count = StrLength - 1; Count >= 0; Count--)
    {
        Value = (Ptr[Count] - '0') << ShiftOffset;
        ShiftOffset++;
        Sum = Sum + Value;
    }
    printf("\n%s %d", Ptr, Sum);
    return 0;
}
