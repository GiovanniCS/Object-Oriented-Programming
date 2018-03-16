#include "spa_client.h"
#include "servizi_derivati.h"

Spa_Client::Spa_Client(const string& no, const string& co, const string& cf, const Indirizzo& i ): Abstract_Client(no,co,cf,i) { }

double Spa_Client::costo_totale() const { return serv.calcolaTotale(); }


void Spa_Client::nuovo_Servizio(const Data &d, std::string nome, std::string tipoOpzionale){
    if(nome == "idromassaggio")
        serv.aggiungi(new Idromassaggio(d));
    else if(nome == "bagnoturco")
        serv.aggiungi(new Bagno_Turco(d));
    else if(nome == "sauna")
        serv.aggiungi(new Sauna(d));
    else if(nome == "massaggio")
        serv.aggiungi(new Massaggio(d,tipoOpzionale));
    else if(nome == "piscina")
        serv.aggiungi(new Piscina(d));
    else if(nome == "palestra")
        serv.aggiungi(new Palestra(d));
}
QString Spa_Client::stampaServizi() const{
    return serv.stampaServizi();
}
unsigned int Spa_Client::numeroServizi()const{
    return serv.size();
}

void Spa_Client::leggiServizio(unsigned int i, Data& d,std::string& tipo,std::string& opz) const{
    serv.leggiServizio(i,d,tipo,opz);
}
