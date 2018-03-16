#ifndef CLIENTI_H
#define CLIENTI_H
#include "hotel_client.h"
//Clienti è il contenitore principale. Permette di inserire, rimuovere e modificare (quest'ultimo, indirettamente attraverso [] che
//ritorna un cliente astratto su cui eseguire le modifiche) i clienti gestiti dal programma.
//E' caratterizzato da una struttura dati di tipo "Double Linked Queue" che permette la rimozione di un elemento in tempo costante ed un agevole decremento
//e decremento degli iteratori
class Clienti{
friend class Iteratore;
private:
    class Nodo{
    public:
        Abstract_Client* cliente;
        Nodo* prev;
        Nodo* next;
        Nodo(Abstract_Client*,Nodo* =0, Nodo* =0);
        ~Nodo();
    };
    Nodo* inizio;
    Nodo* fine;
    void elimina(Nodo*);
public:
    class Iteratore{
    friend class Clienti;
    private:
        Clienti::Nodo* n;
    public:
        bool operator==(const Iteratore&) const;
        bool operator!=(const Iteratore&) const;
        Iteratore& operator++();//incremento prefisso!
        Iteratore& operator--();//decremento postfisso!
        //incremento e decremento sull'iteratore nullo hanno lo stesso effetto, ovvero si riottiene sempre l'iteratore nullo
    };
    ~Clienti();
    Clienti();
    int size() const;
    Iteratore begin() const;
    Iteratore end() const;
    Abstract_Client* operator[](const Iteratore&) const;
    //metodi per rimozione/aggiunta di clienti
    void pushBack(Abstract_Client*);
    //possibile definizione di metodi per l'aggiunta in testa alla lista in tempo costante, non definiti perchè pushBack è sufficiente
    Iteratore eliminaAScelta(const Iteratore&);
    //ritorna l'iteratore all'oggetto che segue il nodo eliminato
};


#endif // CLIENTI_H
