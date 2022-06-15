#include <iostream>
#include "znaki_specjalne.h"
using namespace std;
// Dwukreskowe (do menu)
const string B9 = "\xB9",     // BOK z lewa odnoga
             BA = "\xBA",     // BOK
             BB = "\xBB",     // prawy gorny ROG
             BC = "\xBC",     // prawy dolny ROG
             C8 = "\xC8",     // lewy dolny ROG
             C9 = "\xC9",     // lewy gorny ROG
             CA = "\xCA",     // DOL z odnoga
             CB = "\xCB",     // GORA z odnoga
             CC = "\xCC",     // BOK z prawa odnoga
             CD = "\xCD",     // GORA/DOL
             CE = "\xCE",     // KRZYZ
// Jednokreskowe (do kosci)
             B3 = "\xB3",     // BOK
             BF = "\xBF",     // prawy gorny ROG
             C0 = "\xC0",     // lewy dolny ROG
             C4 = "\xC4",     // GORA/DOL
             D9 = "\xD9",     // prawy dolny ROG
             DA = "\xDA";     // lewy gorny ROG


void w(string znak, short il = 1)
{
    for(int i = 0; i < il; i++)
        cout << znak;
}
