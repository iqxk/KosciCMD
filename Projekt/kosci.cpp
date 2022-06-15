#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <unordered_set>
#include <fstream>

#include "kosci.h"
#include "operacje_na_consoli.h"
#include "znaki_specjalne.h"
using namespace std;

void Gra()
{
    srand(time(NULL));
    TKosci Kosci;

    while(!Kosci.CzyKoniec())
    {
        ClearScreen();
        Kosci.WyswietlPlansze();
        Kosci.WyswietlKosci();
        Kosci.Opcje();
        Kosci.CzyKoniecTury();
    }
    Kosci.Zapisz();

}

void TKosci::WyswietlPlansze()
{
    cout << C9; w(CD, 10); cout << CB << CD << "P1" << CD << CB << CD << "P2" << CD << BB << "\t" << C9; w(CD, 10); cout << CB << CD << "P1" << CD << CB << CD << "P2" << CD << BB << "\n"
         << BA << "  JEDYNKI "    << BA << setw(4) << P(P1,jedynki) << BA << setw(4) << P(P2,jedynki) << BA << "\t" << BA << "  3 JEDN. " << BA << setw(4) << P(P1,trzy_jedn)   << BA << setw(4) << P(P2,trzy_jedn)   << BA << "\n"
         << BA << "  DW\xE0JKI  " << BA << setw(4) << P(P1,dwojki)  << BA << setw(4) << P(P2,dwojki)  << BA << "\t" << BA << "  4 JEDN. " << BA << setw(4) << P(P1,cztery_jedn) << BA << setw(4) << P(P2,cztery_jedn) << BA << "\n"
         << BA << "  TR\xE0JKI  " << BA << setw(4) << P(P1,trojki)  << BA << setw(4) << P(P2,trojki)  << BA << "\t" << BA << "  FULL    " << BA << setw(4) << P(P1,full)        << BA << setw(4) << P(P2,full)        << BA << "\n"
         << BA << "  CZW\xE0RKI " << BA << setw(4) << P(P1,czworki) << BA << setw(4) << P(P2,czworki) << BA << "\t" << BA << "MA\x9DY STRIT" << BA << setw(4) << P(P1,maly_strit)  << BA << setw(4) << P(P2,maly_strit)  << BA << "\n"
         << BA << "  PI\xA4TKI  " << BA << setw(4) << P(P1,piatki)  << BA << setw(4) << P(P2,piatki)  << BA << "\t" << BA << "DU\xBDY STRIT" << BA << setw(4) << P(P1,duzy_strit)  << BA << setw(4) << P(P2,duzy_strit)  << BA << "\n"
         << BA << "  SZ\xE0STKI " << BA << setw(4) << P(P1,szostki) << BA << setw(4) << P(P2,szostki) << BA << "\t" << BA << "  GENERA\x9D " << BA << setw(4) << P(P1,general)     << BA << setw(4) << P(P2,general)     << BA << "\n"
         << BA << "  PREMIA  "    << BA << setw(4) << P(P1,premia)  << BA << setw(4) << P(P2,premia)  << BA << "\t" << BA << "  SZANSA  " << BA << setw(4) << P(P1,szansa)      << BA << setw(4) << P(P2,szansa)      << BA << "\n"
         << C8; w(CD, 10); cout << CA; w(CD, 4); cout << CA; w(CD, 4); cout << BC << "\t" << C8; w(CD, 10); cout << CA; w(CD, 4); cout << CA; w(CD, 4); cout << BC << "\n"
         << "\n"
         << C9; w(CD, 10); cout << CB << CD << "P1" << CD << CB << CD << "P2" << CD << BB << "\t"             << "\xAF Runda" << setw(6) << runda[ktora-1] << " \xAE\n"
         << BA << "  RAZEM   " << BA << setw(4) << P(P1,razem)  << BA << setw(4) << P(P2,razem) << BA << "\t" << "\xAF Tura" << setw(6) << "P" << tura+1 << " \xAE\n"
         << C8; w(CD,10); cout << CA; w(CD, 4); cout << CA; w(CD, 4); cout << BC << "\t"                      << "\xAF Rzut" << setw(7) << ilosc_rzutow << " \xAE\n";
}

string TKosci::DrukujKosc(short kosc, short wiersz)
{
    switch(kosc)
    {
        case 1:
        {
            string jeden[5] = {DA + C4 + C4 + C4 + C4 + C4 + BF,
                               B3 + "     " + B3,
                               B3 + "  o  " + B3,
                               B3 + "     " + B3,
                               C0 + C4 + C4 + C4 + C4 + C4 + D9};
            return jeden[wiersz];
        }
        case 2:
        {
            string dwa[5]   = {DA + C4 + C4 + C4 + C4 + C4 + BF,
                               B3 + "   o " + B3,
                               B3 + "     " + B3,
                               B3 + " o   " + B3,
                               C0 + C4 + C4 + C4 + C4 + C4 + D9};
            return dwa[wiersz];
        }
        case 3:
        {
            string trzy[5]   = {DA + C4 + C4 + C4 + C4 + C4 + BF,
                               B3 + " o   " + B3,
                               B3 + "  o  " + B3,
                               B3 + "   o " + B3,
                               C0 + C4 + C4 + C4 + C4 + C4 + D9};
            return trzy[wiersz];
        }
        case 4:
        {
            string cztery[5]   = {DA + C4 + C4 + C4 + C4 + C4 + BF,
                               B3 + " o o " + B3,
                               B3 + "     " + B3,
                               B3 + " o o " + B3,
                               C0 + C4 + C4 + C4 + C4 + C4 + D9};
            return cztery[wiersz];
        }
        case 5:
        {
            string piec[5]   = {DA + C4 + C4 + C4 + C4 + C4 + BF,
                               B3 + " o o " + B3,
                               B3 + "  o  " + B3,
                               B3 + " o o " + B3,
                               C0 + C4 + C4 + C4 + C4 + C4 + D9};
            return piec[wiersz];
        }
        case 6:
        {
            string szesc[5]   = {DA + C4 + C4 + C4 + C4 + C4 + BF,
                               B3 + " o o " + B3,
                               B3 + " o o " + B3,
                               B3 + " o o " + B3,
                               C0 + C4 + C4 + C4 + C4 + C4 + D9};
            return szesc[wiersz];
        }
    }
}

void TKosci::WyswietlKosci()
{
    cout << DrukujKosc(kosci[0], 0) << "\t" << DrukujKosc(kosci[1], 0) << "\t" << DrukujKosc(kosci[2], 0) << "\t" << DrukujKosc(kosci[3], 0) << "\t" << DrukujKosc(kosci[4], 0) << "\n"
         << DrukujKosc(kosci[0], 1) << "\t" << DrukujKosc(kosci[1], 1) << "\t" << DrukujKosc(kosci[2], 1) << "\t" << DrukujKosc(kosci[3], 1) << "\t" << DrukujKosc(kosci[4], 1) << "\n"
         << DrukujKosc(kosci[0], 2) << "\t" << DrukujKosc(kosci[1], 2) << "\t" << DrukujKosc(kosci[2], 2) << "\t" << DrukujKosc(kosci[3], 2) << "\t" << DrukujKosc(kosci[4], 2) << "\n"
         << DrukujKosc(kosci[0], 3) << "\t" << DrukujKosc(kosci[1], 3) << "\t" << DrukujKosc(kosci[2], 3) << "\t" << DrukujKosc(kosci[3], 3) << "\t" << DrukujKosc(kosci[4], 3) << "\n"
         << DrukujKosc(kosci[0], 4) << "\t" << DrukujKosc(kosci[1], 4) << "\t" << DrukujKosc(kosci[2], 4) << "\t" << DrukujKosc(kosci[3], 4) << "\t" << DrukujKosc(kosci[4], 4) << endl;
}

void TKosci::Opcje()
{
    CzyJoker();
    if(ilosc_rzutow < 3 && wybor != 'b')
    {
        cout << "Zmiana stanu ko\x98\ci:\tOpcje:\n";
        cout << "[1] "; czy_zatrzymane[0] ? cout << "Zatrzymane\t\t" : cout << "Niezatrzymane\t"; cout << "[A] Rzu\x86 ponownie\n";
        cout << "[2] "; czy_zatrzymane[1] ? cout << "Zatrzymane\t\t" : cout << "Niezatrzymane\t"; cout << "[B] Wybierz kategori\xA9\n";
        cout << "[3] "; czy_zatrzymane[2] ? cout << "Zatrzymane\n" : cout << "Niezatrzymane\n";
        cout << "[4] "; czy_zatrzymane[3] ? cout << "Zatrzymane\n" : cout << "Niezatrzymane\n";
        cout << "[5] "; czy_zatrzymane[4] ? cout << "Zatrzymane\n" : cout << "Niezatrzymane" << endl;
        do
        {
            wybor = getch();
            if(wybor == 'A' || wybor == 'B') wybor += 32;
            switch(wybor)
            {
            case '1': czy_zatrzymane[0] ? czy_zatrzymane[0] = false : czy_zatrzymane[0] = true; return;
            case '2': czy_zatrzymane[1] ? czy_zatrzymane[1] = false : czy_zatrzymane[1] = true; return;
            case '3': czy_zatrzymane[2] ? czy_zatrzymane[2] = false : czy_zatrzymane[2] = true; return;
            case '4': czy_zatrzymane[3] ? czy_zatrzymane[3] = false : czy_zatrzymane[3] = true; return;
            case '5': czy_zatrzymane[4] ? czy_zatrzymane[4] = false : czy_zatrzymane[4] = true; return;
            case 'a': LosujKosci(); ilosc_rzutow++; return;
            case 'b': return;
            }
        } while(!((int)wybor >= 49 && (int)wybor <= 53)
                || wybor != 'a' || wybor != 'b');
    }
    else
    {
        if(!czy_wybrane[tura][jedynki])     cout << "[A] JEDYNKI\t\t"        << setw(3) << IloscPunktow(jedynki)               << "  pkt.\n";
        if(!czy_wybrane[tura][dwojki])      cout << "[B] DW\xE0JKI\t\t"      << setw(3) << IloscPunktow(dwojki)                << "  pkt.\n";
        if(!czy_wybrane[tura][trojki])      cout << "[C] TR\xE0JKI\t\t"      << setw(3) << IloscPunktow(trojki)                << "  pkt.\n";
        if(!czy_wybrane[tura][czworki])     cout << "[D] CZW\xE0RKI\t\t"     << setw(3) << IloscPunktow(czworki)               << "  pkt.\n";
        if(!czy_wybrane[tura][piatki])      cout << "[E] PI\xA4TKI\t\t"      << setw(3) << IloscPunktow(piatki)                << "  pkt.\n";
        if(!czy_wybrane[tura][szostki])     cout << "[F] SZ\xE0STKI\t\t"     << setw(3) << IloscPunktow(szostki)               << "  pkt.\n";
        if(!czy_wybrane[tura][trzy_jedn])   cout << "[G] TRZY JEDNAKOWE\t"   << setw(3) << IloscPunktow(trzy_jedn)             << "  pkt.\n";
        if(!czy_wybrane[tura][cztery_jedn]) cout << "[H] CZTERY JEDNAKOWE\t" << setw(3) << IloscPunktow(cztery_jedn)           << "  pkt.\n";
        if(!czy_wybrane[tura][full])        cout << "[I] FULL\t\t"           << setw(3) << IloscPunktow(full, czy_joker)       << "  pkt.\n";
        if(!czy_wybrane[tura][maly_strit])  cout << "[J] MA\x9DY STRIT\t\t"  << setw(3) << IloscPunktow(maly_strit, czy_joker) << "  pkt.\n";
        if(!czy_wybrane[tura][duzy_strit])  cout << "[K] DU\xBDY STRIT\t\t"  << setw(3) << IloscPunktow(duzy_strit, czy_joker) << "  pkt.\n";
        if(!czy_wybrane[tura][general])     cout << "[L] GENERA\x9D\t\t"     << setw(3) << IloscPunktow(general)               << "  pkt.\n";
        if(!czy_wybrane[tura][szansa])      cout << "[M] SZANSA\t\t"         << setw(3) << IloscPunktow(szansa)                << "  pkt.\n";
        cout << endl;
        do
        {
            wybor = getch();
            if((int)wybor >= 65 && (int)wybor <= 90) wybor += 32;
            //cout << wybor << " " << (int)wybor-97 << endl; system("pause");
        } while (!((int)wybor >= 97 && (int)wybor <= 122) || czy_wybrane[tura][(int)wybor-97]);
        short kategoria_temp = (int)wybor-97;
        punktacja[tura][kategoria_temp] = IloscPunktow(kategoria_temp, czy_joker, czy_podpowiedz);
        punktacja[tura][razem] += IloscPunktow(kategoria_temp, czy_joker, czy_podpowiedz);
        czy_wybrane[tura][kategoria_temp] = true;
        if(czy_wybrane[tura][jedynki] && czy_wybrane[tura][dwojki] && czy_wybrane[tura][trojki] &&
           czy_wybrane[tura][czworki] && czy_wybrane[tura][piatki] && czy_wybrane[tura][szostki])
        {
            short suma = 0;
            for(int i = 0; i < 6; i++)
                suma += punktacja[tura][i];
            if(suma >= 63 && !czy_wybrane[tura][premia])
            {
                punktacja[tura][premia] += 35;
                punktacja[tura][razem] += 35;
                czy_wybrane[tura][premia] = true;
            }
        }
        if(czy_uzyto_jokera[tura] && !czy_przyznano_premie_jokera[tura])
        {
            punktacja[tura][premia] += 100;
            punktacja[tura][razem] += 100;
            czy_przyznano_premie_jokera[tura] = true;
            czy_wybrane[tura][premia] = true;
        }
        czy_zakonczyc_ture = true;
    }
}

short TKosci::IloscPunktow(const short kategoria, bool joker, bool czy_podpowiedz)
{
    vector<short> k = {kosci[0], kosci[1], kosci[2], kosci[3], kosci[4]};
    sort(k.begin(), k.end());
    short suma = 0;
    bool czy_prawda = false;
    switch(kategoria)
    {
        case trzy_jedn:
        {
            for(int i = 0; i < 3; i++)
                if(k[i] == k[i+1] && k[i+1] == k[i+2])
                    czy_prawda = true;
            if(czy_prawda)
                for(int i = 0; i < 5; i++)
                    suma += k[i];
            return suma;
        }
        case cztery_jedn:
        {
            for(int i = 0; i < 2; i++)
                if(k[i] == k[i+1] && k[i+1] == k[i+2] && k[i+2] == k[i+3])
                    czy_prawda = true;
            if(czy_prawda)
                for(int i = 0; i < 5; i++)
                    suma += k[i];
            return suma;
        }
        case full:
        {
            if(joker)
            {
                if(czy_podpowiedz)
                    return 25;
                czy_uzyto_jokera[tura] = true;
                return 25;
            }
            if((k[0] == k[1] && k[1] == k[2]
                && k[3] == k[4])
                ||
               (k[0] == k[1]
                && k[2] == k[3] && k[3] == k[4]))
                return 25;
            else return 0;
        }
        case maly_strit:
        {
            if(joker)
            {
                if(czy_podpowiedz)
                    return 30;
                czy_uzyto_jokera[tura] = true;
                return 30;
            }
            unordered_set<short> temp;
            temp.insert(k.begin(), k.end());
            while(!k.empty()) k.pop_back();
            for(const int&x: temp) k.push_back(x);
            short roznica = -6;
            if(k[1] - k[0] == 1) roznica = 1;
            else if(k[1] - k[0] == -1) roznica = -1;
            for(int i = 0; i < 2; i++)
                for(int j = i; j < i+3; j++)
                    if(k[j] != k[0] + j*roznica)
                        return 0;
            return 30;
        }
        case duzy_strit:
        {
            if(joker)
            {
                if(czy_podpowiedz)
                    return 40;
                czy_uzyto_jokera[tura] = true;
                return 40;
            }
            //k.erase(unique(k.begin(), k.end()));
            short roznica = -6;
            if(k[1] - k[0] == 1) roznica = 1;
            else if(k[1] - k[0] == -1) roznica = -1;
            for(int i = 0; i < 5; i++)
                if(k[i] != k[0] + i*roznica)
                    return 0;
            return 40;
        }
        case general:
        {
            short ilosc_oczek = k[0];
            for(int i = 1; i < 5; i++)
                if(k[i] != ilosc_oczek)
                    return 0;
            return 50;
        }
        case szansa:
        {
            for(int i = 0; i < 5; i+=1)
                suma += k[i];
            return suma;
        }
        default: // JEDYNKI, ..., SZOSTKI
        {
            for(int i = 0; i < 5; i++)
                if(k[i] == kategoria+1)
                    suma += kategoria+1;
            return suma;
        }
    }
    return suma;
}

void TKosci::Zapisz()
{
    fstream zapis_podglad;
    string imieP1, imieP2;
    ClearScreen();
    cout << "Podaj imi\xA9 gracza P1: "; cin >> imieP1;
    cout << "Podaj imi\xA9 gracza P2: "; cin >> imieP2;
    zapis_podglad.open("lista_gier.txt", ios::app);
    zapis_podglad << imieP1 << "," << punktacja[P1][razem] << ","
                  << punktacja[P2][razem] << "," << imieP2 << endl;
    zapis_podglad.close();

    fstream zapis_szczegoly;
    zapis_szczegoly.open("szczegoly_gier.txt", ios::app);
    for(int gracz = 0; gracz < 2; gracz++)
        for(int kategoria = 0; kategoria < 15; kategoria++)
            zapis_szczegoly << punktacja[gracz][kategoria] << ",";
    zapis_szczegoly << endl;
    zapis_szczegoly.close();
}
