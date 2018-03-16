#ifndef UTENTI_H
#define UTENTI_H
#include "utente.h"

//Utenti rappresenta il contenitore di tutti gli utenti riconosciuti dal programma
//E' implementato come una lista di nodi e il distruttore è ridefinito in modo da garantire la distruzione profonda
class Utenti{
private:
    class Nodo{
    public:
        Utente u;
        Nodo* next;
        Nodo(Utente ,Nodo* =0);
    };
    Nodo* inizio;
    void el(Nodo*);
public:
    Utenti();
    ~Utenti();
    void aggiungi(std::string,std::string,std::string);
    int rimuovi(int);
    unsigned int size() const;
    unsigned int contaAmministratori() const;
    void leggiUtente(unsigned int,string& ,string&, string&) const;
    void salvaUtente(unsigned int, std::string , std::string, std::string);
    bool esiteUtente(string,string,string);
    Utente* operator[](unsigned int);
};

#endif // UTENTI_H
