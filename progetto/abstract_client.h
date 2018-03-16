#ifndef ABSTRACT_CLIENT_H
#define ABSTRACT_CLIENT_H
#include "indirizzo.h"
//rappresenta la base di derivazione di tutti i clienti dell'hotel
//fornisce funzionalita di impostazione e "ritorno" delle principali caratteristiche condivise da tutti i clienti
//distruttore virtuale
class Abstract_Client{
private:
    string nome, cognome, cod_fisc;
    Indirizzo ind;
public:
    //Distruttore Virtuale
    virtual ~Abstract_Client();
    //Metodo virtuale puro per il calcolo del prezzo finale da pagare
    virtual double costo_totale() const=0;

    //Costruttore con 4 parametri
    Abstract_Client(const string&, const string&, const string&, const Indirizzo& );

    void setNome(const string&);
    void setCognome(const string&);
    void setCodiceFiscale(const string&);
    void setIndirizzo(const string& ,const string& ,const string& ,const string& ,const string&);

    string getNome() const;
    string getCognome() const;
    string getCodiceFiscale() const;
    //getIndirizzo() ritorna una stringa con tutte le info sull'indirizzo del cliente
    string getIndirizzo() const;
    //getPuntIndirizzo() ritorna un puntatore costante ad Indirizzo su cui poi e possibilie accedere separatamente
    //ad ogni campo dato (in sola lettura)
    const Indirizzo* getPuntIndirizzo() const;

};
#endif // ABSTRACT_CLIENT_H
