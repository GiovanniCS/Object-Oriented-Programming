#ifndef HOTEL_CLIENT_H
#define HOTEL_CLIENT_H
#include "restaurant_client.h"
#include "spa_client.h"

//Rappresenta il cliente d'hotel, ovvero il cliente che pernotta per almeno una notte nella struttura,
//oltre alle caratteristiche ereditate da spa e restaurant client possiede anche la data di check-in e quella
//di check-out; vengono calcolati inolte i giorni di residenza(sfruttando l'operatore di disuguaglianza di Data),
//non usati nel progetto ma utili per ulteriori sviluppi.
//Presente overriding del metodo costo_totale().
class Hotel_Client: public Restaurant_Client, public Spa_Client{
private:
    Data check_in, check_out;
    int giorni_residenza;
public:
    Hotel_Client(const string&, const string&, const string&, const Indirizzo&, const Data& ,const Data&);
    double costo_totale() const;
    Data getIn() const;
    Data getOut() const;
};

#endif
