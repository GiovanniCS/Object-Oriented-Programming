#include "abstract_client.h"
Abstract_Client::~Abstract_Client(){}

Abstract_Client::Abstract_Client(const string& nom, const string& cogn, const string& cod, const Indirizzo& in):
                                 nome(nom),cognome(cogn),cod_fisc(cod),ind(in){}

void Abstract_Client::setNome(const string& a) { nome = a; }

void Abstract_Client::setCognome(const string& a) { cognome = a; }

void Abstract_Client::setCodiceFiscale(const string& a) { cod_fisc = a; }

void Abstract_Client::setIndirizzo(const string& a ,const string& b , const string& c ,const string& d, const string& e) {
    ind.setStato(e); ind.setProvincia(d), ind.setCitta(c); ind.setVia(b); ind.setNumeroCivico(a);
}

string Abstract_Client::getNome() const{ return nome; }

string Abstract_Client::getCognome() const{ return cognome; }

string Abstract_Client::getCodiceFiscale() const{ return cod_fisc; }

string Abstract_Client::getIndirizzo() const{
    string spz=" ";
    return ind.getVia() + spz + ind.getNumeroCivico() + spz +  ind.getCitta() + spz + ind.getProvincia() + spz + ind.getStato();
}
const Indirizzo* Abstract_Client::getPuntIndirizzo() const{ return &ind; }
