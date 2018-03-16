#include "restaurant_client.h"

Restaurant_Client::Restaurant_Client(const string& no, const string& co, const string& cf, const Indirizzo& i ): Abstract_Client(no,co,cf,i) { }

double Restaurant_Client::costo_totale() const { return scontrini.calcolaTotale(); }

void Restaurant_Client::nuovo_Scontrino(const Data& d, int i, double db){
    scontrini.aggiungi(d,i,db);
}
QString Restaurant_Client::stampaScontrini() const{
    return scontrini.stampaScontrini();
}

unsigned int Restaurant_Client::numeroScontrini()const{
    return scontrini.size();
}
void Restaurant_Client::leggiScontrino(unsigned int i,Data& d ,int& g , double& s) const{
    scontrini.leggiScontrino(i,d,g,s);
}
