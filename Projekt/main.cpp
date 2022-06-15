#include <iostream>
#include <windows.h>
#include <conio.h>

#include "menu.h"
#include "operacje_na_consoli.h"
#include "kosci.h"
using namespace std;

int main()
{
    char wybor;
    while(true)
    {
        ClearScreen();
        WyswietlMenu();
        do
        {
            wybor = getch();
            switch(wybor)
            {
            case '1':
                Gra();
                break;
            case '2':
                Historia();
                break;
            case '3':
                Zasady();
                break;
            case '4':
                return 0;
            }
        } while(!((int)wybor >= 49 && (int)wybor <= 52));
    }
    return 0;
}
