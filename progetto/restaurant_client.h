#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H
#include "abstract_client.h"
#include "lista_scontrini.h"

//classe che rappresenta il cliente di ristorante ovvero colui che, dell'intero hotel, usufruisce solo del ristorante.
class Restaurant_Client: virtual public Abstract_Client{
private:
        //Oggetto che rappresenta l'insieme degli scontrini del ristorante relativi al cliente.
        Lista_Scontrini scontrini;
public:
    Restaurant_Client(const string&, const string&, const string&, const Indirizzo& );
    // Metodo virtuale che ritorna il prezzo totale che il cliente deve pagare
    double costo_totale() const;
    //aggiunta di un nuovo scontrino relativo al cliente
    void nuovo_Scontrino(const Data&, int, double);
    //ritorna il testo della QLabel che mostra tutti gli scontrini
    QString stampaScontrini() const;
    //calcola il numero di scontrini totali
    unsigned int numeroScontrini()const;
    //metodo usato nel salvataggio dei dati per recuperare le info dell'i-esimo scontrino
    void leggiScontrino(unsigned int,Data&,int&, double&) const;
};

#endif
