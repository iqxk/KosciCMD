#ifndef KOSCI_H_INCLUDED
#define KOSCI_H_INCLUDED
void Gra();

class TKosci
{
private:
    char wybor;
    static constexpr short P1 = 0,
                           P2 = 1,
                           jedynki = 0, dwojki = 1, trojki = 2, czworki = 3, piatki = 4, szostki = 5,
                           trzy_jedn = 6, cztery_jedn = 7, full = 8, maly_strit = 9, duzy_strit = 10, general = 11, szansa = 12,
                           premia = 13, razem = 14;

    short tura = P1,
          ilosc_rzutow = 1,
          kosci[5],
          punktacja[2][15] = {},
          ktora = 1; // Ktora runda, sluzy jako index do 'runda'
    bool czy_zakonczyc_ture = false,
         czy_podpowiedz = false,
         czy_zatrzymane[5] = {},
         czy_wybrane[2][14] = {},
         czy_joker = false,
         czy_uzyto_jokera[2] = {},
         czy_przyznano_premie_jokera[2] = {};
    std::string runda[13] = {"I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII","XIII"};

    std::string DrukujKosc(short, short);
    std::string P(short gracz, short kategoria){ // Funkcja wyswietlajaca zawartosc zmiennej 'punktacja' dla konkretnego gracza i kategorii
        if(kategoria == razem)
            return std::to_string(punktacja[gracz][razem]) + " ";
        if(czy_wybrane[gracz][kategoria])
            return std::to_string(punktacja[gracz][kategoria]) + " ";
        return "";
    }
    void LosujKosci(){
        for(int i = 0; i < 5; i++)
            if(!czy_zatrzymane[i])
                kosci[i] = rand() % 6 + 1;
    }
    short IloscPunktow(const short, bool = false, bool = true);
    void CzyJoker(){
        if(czy_wybrane[tura][general] && punktacja[tura][general] != 0)
        {
            short ilosc_oczek = kosci[0];
            for(int i = 1; i < 5; i++)
                if(kosci[i] != (int)ilosc_oczek)
                {
                    czy_joker = false;
                    return;
                }
            czy_joker = true;
        }
        else
            czy_joker = false;
    }
public:
    TKosci(){LosujKosci();}
    bool CzyKoniec() {return ktora > 13;}
    void WyswietlPlansze();
    void WyswietlKosci();
    void Opcje();
    void CzyKoniecTury(){
        if(czy_zakonczyc_ture)
        {
            if(tura == P1) tura = P2;
            else{tura = P1; ktora++;}
            ilosc_rzutow = 1;
            for(int i = 0; i < 5; i++) czy_zatrzymane[i] = false;
            LosujKosci();
            wybor = 0;
            czy_zakonczyc_ture = false;
        }
    }
    void Zapisz();
};

#endif // KOSCI_H_INCLUDED
