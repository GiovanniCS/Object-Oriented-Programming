#include "utente.h"
Utente::Utente(string a ,string b, string c): username(a), password(b), tipo(c){}
void Utente::setUsername(string a){ username = a; }
void Utente::setPassword(string a){ password = a; }
void Utente::setTipo(string a){ tipo = a; }
string Utente::getUsername() const{ return username; }
string Utente::getPassword() const{ return password; }
string Utente::getTipo() const{ return tipo; }
