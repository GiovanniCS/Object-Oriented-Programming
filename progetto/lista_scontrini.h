#ifndef LISTASCONTRINI_H
#define LISTASCONTRINI_H
#include "data.h"
#include <QString>

//contenitore degli scontrini relativi ad uno specifico cliente di ristorante o di Hotel
//Ogni nodo della lista è uno scontrino caratterizzato da una data, il numero di persone, il totale pagato
//e un puntatore allo scontrino successivo. Gestione della memoria in modo non condiviso.
//L'intera struttura dati è allocata sullo heap e la distruzione degli oggetti è profonda.
class Lista_Scontrini{
private:
    //Classe annidata, rappresenta il singolo scontrino
    class Scontrino{
    public:
        Data data;
        int num_persone;
        double totale;
        Scontrino* next;
        Scontrino(const Data&, int, double, Scontrino* =0);
    };
    static void elimina(Scontrino*);
    //lista di scontrini.
    Scontrino* inizio;
public:
    ~Lista_Scontrini();
    Lista_Scontrini();
    void aggiungi(const Data& d, int i, double db);
    double calcolaTotale() const;
    QString stampaScontrini() const;
    unsigned int size() const;
    void leggiScontrino(unsigned int,Data&,int&, double&) const;
};

#endif
