#ifndef SPA_CLIENT_H
#define SPA_CLIENT_H
#include "abstract_client.h"
#include "contenitore_servizi.h"

//classe che rappresenta il cliente della Spa, ovvero colui che, dell'intero hotel, usufruisce solo dei servizi "Spa".
class Spa_Client: virtual public Abstract_Client{
private:
        Contenitore_Servizi serv;
public:
    Spa_Client(const string&, const string&, const string&, const Indirizzo& );
    // Metodo virtuale che ritorna il prezzo totale che il cliente deve pagare
    double costo_totale() const;
    //Aggiunta di un servizio relativo al cliente - data, nome servzio, tipo opzionale es: Tailandese se nome servizo == massaggio
    void nuovo_Servizio(const Data&, std::string,std::string = "");
    QString stampaServizi() const;
    unsigned int numeroServizi()const;
    void leggiServizio(unsigned int, Data&,std::string&,std::string&) const;
};
#endif
