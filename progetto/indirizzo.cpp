#include "indirizzo.h"

Indirizzo::Indirizzo(const string& a, const string& b, const string& c, const string& d, const string& e):
            via(a),n_civico(b),citta(c),provincia(d), stato(e) {}

string Indirizzo::getStato() const{ return stato;}

void Indirizzo::setStato(const string& s){ stato=s;}

string Indirizzo::getProvincia() const{ return provincia;}

void Indirizzo::setProvincia(const string& s){ provincia=s; }

string Indirizzo::getCitta() const{ return citta; }

void Indirizzo::setCitta(const string& s){ citta=s;}

string Indirizzo::getVia() const{ return via;}

void Indirizzo::setVia(const string& s){ via=s; }

string Indirizzo::getNumeroCivico() const{ return n_civico;}

void Indirizzo::setNumeroCivico(const string& s){ n_civico=s;}
