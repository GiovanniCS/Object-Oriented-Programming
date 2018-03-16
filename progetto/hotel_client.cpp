#include "hotel_client.h"
//Hotel_Client deriva da Spa e Restaurant e forma un diamante nella gerarchia di derivazione.
//Per questo si occupa esplicitamente della costruzione di Abstract_Client (derivato virtualmente)
Hotel_Client::Hotel_Client(const string& no, const string& co, const string& cf, const Indirizzo& i, const Data& in,const Data& out):
    Abstract_Client(no,co,cf,i), Restaurant_Client(no,co,cf,i), Spa_Client(no,co,cf,i), check_in(in), check_out(out){
        int g = 0;
        Data temp = check_in;
        while(temp <= check_out){
            ++g;
            ++temp;
        }
    giorni_residenza = g;
}
double Hotel_Client::costo_totale() const{
    return Spa_Client::costo_totale() + Restaurant_Client::costo_totale() +45*giorni_residenza;//45 euro per ogni giorno di residenza nell'hotel
}

Data Hotel_Client::getIn() const { return check_in; }
Data Hotel_Client::getOut() const { return check_out; }
