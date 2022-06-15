#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "menu.h"
#include "znaki_specjalne.h"
#include "operacje_na_consoli.h"
using namespace std;

void Zasady()
{
    ClearScreen();
    cout << "Gra polega na rzucaniu ko\x98\x86mi, aby uzyska\x86 okre\x98lone uk\x88\aady oczek, za kt\xA2re otrzymuje si\xA9 punkty.\n"
         << "\n"
         << "W ka\xBE\dej z trzynastu rund gracze maj\xA5 do dyspozycji trzy rzuty. Pierwszy z nich odbywa si\xA9 zawsze wszystkimi pi\xA9\cioma\n"
         << "kostkami, a w drugim i trzecim, kt\xA2re nie s\xA5 obowi\xA5zkowe, wybrane kostki mog\xA5 zosta\x86 zatrzymane - rzut odbywa si\xA9 wtedy\n"
         << "tylko niezatrzymanymi.\n"
         << "\n"
         << "Po wykonaniu rzut\xA2w, uk\x88\aad oczek uzyskany na kostkach musi zosta\x86 zapisany przez gracza w tabeli punktacji do jednej\n"
         << "z trzynastu kategorii. Raz wybrana kategoria nie mo\xBE\x65 by\x86 p\xA2\xABniej ponownie wybrana.\n"
         << "\n"
         << "\n"
         << "\n"
         << "Strona 1/3 - naci\x98nij enter aby przej\x98\x86 dalej";
    cin.clear(); cin.sync(); cin.get();
    ClearScreen();
    cout << C9; w(CD, 10); cout << CB << CD << "P1" << CD << CB << CD << "P2" << CD << BB << "\t" << C9; w(CD, 10); cout << CB << CD << "P1" << CD << CB << CD << "P2" << CD << BB << "\n"
         << BA << "  JEDYNKI "    << BA << "    " << BA << "    " << BA << "\t" << BA << "  3 JEDN. "    << BA << "    " << BA << "    " << BA << "\t" << "Kategorie lewej cz\xA9\x98\ci tabeli\n"
         << BA << "  DW\xE0JKI  " << BA << "    " << BA << "    " << BA << "\t" << BA << "  4 JEDN. "    << BA << "    " << BA << "    " << BA << "\n"
         << BA << "  TR\xE0JKI  " << BA << "    " << BA << "    " << BA << "\t" << BA << "  FULL    "    << BA << "    " << BA << "    " << BA << "\t" << "JEDYNKI, DW\xE0JKI, ..., SZ\xE0STKI - suma oczek liczb z wybranej kategorii\n"
         << BA << "  CZW\xE0RKI " << BA << "    " << BA << "    " << BA << "\t" << BA << "MA\x9DY STRIT" << BA << "    " << BA << "    " << BA << "\t" << "(np. 4, 3, 4, 4, 1 - gracz wskazuje \"CZW\xE0RKI\", wi\xA9\c zyskuje 12 pkt.).\n"
         << BA << "  PI\xA4TKI  " << BA << "    " << BA << "    " << BA << "\t" << BA << "DU\xBDY STRIT" << BA << "    " << BA << "    " << BA << "\t" << "Je\x98li w lewych kategoriach tabeli uzyska si\xA9 razem 63 pkt. lub wi\xA9\cej,\n"
         << BA << "  SZ\xE0STKI " << BA << "    " << BA << "    " << BA << "\t" << BA << "  GENERA\x9D " << BA << "    " << BA << "    " << BA << "\t" << "to dodatkowo otrzymuje si\xA9 premi\xA9 w wysoko\x98\ci 35pkt.\n"
         << BA << "  PREMIA  "    << BA << "    " << BA << "    " << BA << "\t" << BA << "  SZANSA  "    << BA << "    " << BA << "    " << BA << "\n"
         << C8; w(CD, 10); cout << CA; w(CD, 4); cout << CA; w(CD, 4); cout << BC << "\t" << C8; w(CD, 10); cout << CA; w(CD, 4); cout << CA; w(CD, 4); cout << BC << "\n"
         << "\n"
         << C9; w(CD, 10); cout << CB << CD << "P1" << CD << CB << CD << "P2" << CD << BB << "\n"
         << BA << "  RAZEM   " << BA << "    " << BA << "    " << BA << "\n"
         << C8; w(CD,10); cout << CA; w(CD, 4); cout << CA; w(CD, 4); cout << BC << "\n"
         << "\n"
         << "Kategorie prawej cz\xA9\x98\ci tabeli\n"
         << "\n"
         << "3 JEDN.    - suma oczek wszystkich pi\xA9\ciu kostek, je\x98li wyst\xA9puj\xA5 co najmniej trzy jednakowe liczby oczek\n"
         << "4 JEDN.    - suma oczek wszystkich pi\xA9\ciu kostek, je\x98li wyst\xA9puj\xA5 co najmniej cztery jednakowe liczby oczek\n"
         << "FULL       - 25 pkt., je\x98li w uk\x88\x61\dzie wyst\xA9puj\xA5 trzy jednakowe liczby oczek oraz dwie inne jednakowe\n"
         << "MA\x9DY STRIT - 30 pkt., je\x98li przynajmniej cztery ko\x98\ci maj\xA5 kolejne liczby oczek\n"
         << "DU\x8DY STRIT - 40 pkt., je\x98li wszystkie ko\x98\ci maj\xA5 kolejne liczby oczek\n"
         << "GENERA\x9D    - 50 pkt., je\x98li liczba oczek na wszystkich kostkach jest jednakowa\n"
         << "SZANSA     - niezale\xBEnie od uk\x88\x61\du kostek uzyskuje si\xA9 sum\xA9 oczek z wszystkich kostek\n"
         << "\n"
         << "\n"
         << "\n"
         << "Strona 2/3 - naci\x98nij enter aby przej\x98\x86 dalej";
    cin.clear(); cin.sync(); cin.get();
    ClearScreen();
    cout << "Wyboru ka\xBE\dej z wolnych kategorii mo\xBEna dokona\x86 niezale\xBEnie od posiadanego uk\x88\x61\du, przy czym je\x98li nie spe\x88nia on\n"
         << "okre\x98lonych wymaga\xE4, to otrzymuje si\xA9 0 pkt. (taki wyb\xA2r za 0 pkt. jest czasami konieczny, kiedy uk\x88\x61\d nie pasuje\n"
         << "do \xBE\x61\dnej z wolnych kategorii).\n"
         << "\n"
         << "Drugi, trzeci i ka\xBE\dy kolejny wyrzucony genera\x88 mo\xBE\x65 zosta\x86 u\xBEyty jako joker, je\x98li kategoria \"GENERA\x9D\" i kategoria\n"
         << "lewej cz\xA9\x98\ci tabeli odpowiadaj\xA5\ca danemu genera\x88owi s\xA5 ju\xBE wykorzystane. Jokera zapisuje si\xA9 w prawych kategoriach\n"
         << "tabeli punktacji, otrzymuj\xA5\c stosown\xA5 liczb\xA9 punkt\xA2w (np. 25 pkt. za \"FULL\" itd.), chyba \xBE\x65 wszystkie prawe kategorie\n"
         << "s\xA5 ju\xBE wykorzystane, wtedy trzeba go zapisa\x86 do jednej z lewych za 0 pkt. Je\xBE\x65li joker zosta\x88 u\xBEyty co najmniej raz, to\n"
         << "otrzymuje si\xA9 100 pkt. premii.\n"
         << "\n"
         << "\n"
         << "Strona 3/3 - naci\x98nij enter aby wr\xA2\ci\x86 do menu";
    cin.clear(); cin.sync(); cin.get();
}

void Historia()
{
    static constexpr short P1 = 0,
                           P2 = 1,
                           jedynki = 0, dwojki = 1, trojki = 2, czworki = 3, piatki = 4, szostki = 5,
                           trzy_jedn = 6, cztery_jedn = 7, full = 8, maly_strit = 9, duzy_strit = 10, general = 11, szansa = 12,
                           premia = 13, razem = 14;
    short odczyt_pkt[2][15];
    ifstream odczyt_podglad;
    odczyt_podglad.open("lista_gier.txt", ios::in);
    if(odczyt_podglad.good())
    {
        string linia, token;
        int opcja, index = 0, i = 0;
        ClearScreen();
        while(!odczyt_podglad.eof())
        {
            getline(odczyt_podglad, linia);
            istringstream iss(linia);
            while(getline(iss, token, ','))
            {
                switch(i)
                {
                case 0:
                    cout << "[" << index+1 << "]\t"
                         << setw(10) << token << " ";
                    break;
                case 1:
                    cout << setw(3) << token << "pkt.  :  ";
                    break;
                case 2:
                    cout << setw(3) << token << "pkt.";
                    break;
                case 3:
                    cout << " " << token << " ";
                    break;
                }
                i++;
            }
            cout << "\n";
            i = 0;
            index++;
        }
        // WYBOR OPCJI
        cout << "[0] Wyj\x98\cie\n";
        cout << "Wpisz numer gry i zatwierd\xAB enterem: ";
        cin >> opcja;
        while (cin.fail() || opcja < 0 || opcja > index-1)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "B\x88\x61\d!" << endl;
            cout << "Wpisz numer gry i zatwierd\xAB enterem: ";
            cin >> opcja;
        }
        if(opcja == 0) return;
        // ------------
        ifstream odczyt_szczegoly;
        odczyt_szczegoly.open("szczegoly_gier.txt", ios:: in);
        if(odczyt_szczegoly.good())
        {
            string linia;
            ClearScreen();
            for(int i = 0; i < opcja; i++) getline(odczyt_szczegoly, linia);
            istringstream iss(linia);
            int gracz = 0, kategoria = 0;
            while(getline(iss, token, ','))
            {
                if(kategoria < 15)
                {
                    odczyt_pkt[gracz][kategoria] = stoi(token);
                    kategoria++;
                    if(kategoria >= 15)
                    {
                        kategoria = 0;
                        gracz++;
                    }
                }
            }
            cout << C9; w(CD, 10); cout << CB << CD << "P1" << CD << CB << CD << "P2" << CD << BB << "\t" << C9; w(CD, 10); cout << CB << CD << "P1" << CD << CB << CD << "P2" << CD << BB << "\n"
                 << BA << "  JEDYNKI "    << BA << setw(3) << odczyt_pkt[P1][jedynki] << " " << BA << setw(3) << odczyt_pkt[P2][jedynki] << " " << BA << "\t" << BA << "  3 JEDN. "    << BA << setw(3) << odczyt_pkt[P1][trzy_jedn]   << " " << BA << setw(3) << odczyt_pkt[P2][trzy_jedn]   << " " << BA << "\n"
                 << BA << "  DW\xE0JKI  " << BA << setw(3) << odczyt_pkt[P1][dwojki]  << " " << BA << setw(3) << odczyt_pkt[P2][dwojki]  << " " << BA << "\t" << BA << "  4 JEDN. "    << BA << setw(3) << odczyt_pkt[P1][cztery_jedn] << " " << BA << setw(3) << odczyt_pkt[P2][cztery_jedn] << " " << BA << "\n"
                 << BA << "  TR\xE0JKI  " << BA << setw(3) << odczyt_pkt[P1][trojki]  << " " << BA << setw(3) << odczyt_pkt[P2][trojki]  << " " << BA << "\t" << BA << "  FULL    "    << BA << setw(3) << odczyt_pkt[P1][full]        << " " << BA << setw(3) << odczyt_pkt[P2][full]        << " " << BA << "\n"
                 << BA << "  CZW\xE0RKI " << BA << setw(3) << odczyt_pkt[P1][czworki] << " " << BA << setw(3) << odczyt_pkt[P2][czworki] << " " << BA << "\t" << BA << "MA\x9DY STRIT" << BA << setw(3) << odczyt_pkt[P1][maly_strit]  << " " << BA << setw(3) << odczyt_pkt[P2][maly_strit]  << " " << BA << "\n"
                 << BA << "  PI\xA4TKI  " << BA << setw(3) << odczyt_pkt[P1][piatki]  << " " << BA << setw(3) << odczyt_pkt[P2][piatki]  << " " << BA << "\t" << BA << "DU\xBDY STRIT" << BA << setw(3) << odczyt_pkt[P1][duzy_strit]  << " " << BA << setw(3) << odczyt_pkt[P2][duzy_strit]  << " " << BA << "\n"
                 << BA << "  SZ\xE0STKI " << BA << setw(3) << odczyt_pkt[P1][szostki] << " " << BA << setw(3) << odczyt_pkt[P2][szostki] << " " << BA << "\t" << BA << "  GENERA\x9D " << BA << setw(3) << odczyt_pkt[P1][general]     << " " << BA << setw(3) << odczyt_pkt[P2][general]     << " " << BA << "\n"
                 << BA << "  PREMIA  "    << BA << setw(3) << odczyt_pkt[P1][premia]  << " " << BA << setw(3) << odczyt_pkt[P2][premia]  << " " << BA << "\t" << BA << "  SZANSA  "    << BA << setw(3) << odczyt_pkt[P1][szansa]      << " " << BA << setw(3) << odczyt_pkt[P2][szansa]      << " " << BA << "\n"
                 << C8; w(CD, 10); cout << CA; w(CD, 4); cout << CA; w(CD, 4); cout << BC << "\t" << C8; w(CD, 10); cout << CA; w(CD, 4); cout << CA; w(CD, 4); cout << BC << "\n"
                 << "\n"
                 << C9; w(CD, 10); cout << CB << CD << "P1" << CD << CB << CD << "P2" << CD << BB << "\n"
                 << BA << "  RAZEM   " << BA << setw(3) << odczyt_pkt[P1][razem]  << " " << BA << setw(3) << odczyt_pkt[P2][razem] << " " << BA << "\n"
                 << C8; w(CD,10); cout << CA; w(CD, 4); cout << CA; w(CD, 4); cout << BC << "\n"
                 << "Naci\x98nij enter aby wr\xA2\ci\x86 do menu" << endl;
                 cin.clear(); cin.sync(); cin.get();
                 odczyt_szczegoly.close();
        }
        else
        {
            cout << "\n\n\n\n\n"
                 << "B\x88\xA5\d!\n"
                 << "Plik \"szczegoly_gier.txt\" nie istnieje lub jest pusty. Je\xBE\x65li nie posiadasz kopii tego pliku,\n"
                 << "zaleca si\xA9 usuni\xA9\cie \"lista_gier.txt\" oraz \"szczegoly_gier.txt\" aby naprawi\x86 problem.\n"
                 << "UWAGA - utracisz dotychczasow\xA5 histori\xA9 gier!\n"
                 << "Naci\x98nij enter aby wr\xA2\ci\x86 do menu" << endl;
                 cin.clear(); cin.sync(); cin.get();
        }
        odczyt_podglad.close();
    }
    else
    {
        cout << "\n\n\n\n\nBrak historii rozegranych gier.\n"
             << "Naci\x98nij enter aby kontynuowa\x86" << endl;
                 cin.clear(); cin.sync(); cin.get();
    }

}

void WyswietlMenu()
{
    cout << C9; w(CD, 21); cout << BB << "\n"
         << BA << "        Ko\x98\ci        " << BA << "\n"
         << CC; w(CD, 21); cout << B9 << "\n"
         << BA << " [1] Rozpocznij gr\xA9  " << BA << "\n"
         << BA << " [2] Historia meczy  " << BA << "\n"
         << BA << " [3] Zasady          " << BA << "\n"
         << BA << " [4] Wyj\x98\cie         " << BA << "\n"
         << CC; w(CD, 21); cout << B9 << "\n"
         << BA << " Wykona\x88 Igor Kucyk  " << BA << "\n"
         << C8; w(CD, 21); cout << BC << "\n";
}
