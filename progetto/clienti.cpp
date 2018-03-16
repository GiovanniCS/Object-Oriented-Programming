#include "clienti.h"

//Costruzione - Distruzione Nodo
Clienti::Nodo::Nodo(Abstract_Client* a, Nodo* p, Nodo* n): cliente(a), prev(p), next(n){}
Clienti::Nodo::~Nodo(){ delete cliente; }
void Clienti::elimina(Nodo* n){
    if(!n)  return;
    elimina(n->next);
    delete n;
}

//Costruzione - Distruzione Clienti
Clienti::~Clienti(){ elimina(inizio); }//distruzione profonda
Clienti::Clienti():inizio(0),fine(0){}


//Metodi inerenti Iteratore
Clienti::Iteratore Clienti::begin() const{
    Iteratore aux;
    aux.n = inizio; return aux;
}
Clienti::Iteratore Clienti::end() const{
    Iteratore aux;
    aux.n = 0; return aux;
}
Clienti::Iteratore& Clienti::Iteratore::operator ++(){
    n = n ? n->next : 0;
    return *this;
}
Clienti::Iteratore& Clienti::Iteratore::operator --(){
    n = n ? n->prev : 0;
    return *this;
}
bool Clienti::Iteratore::operator ==(const Iteratore& i)const{
    return n == i.n;
}
bool Clienti::Iteratore::operator !=(const Iteratore& i)const{
    return n != i.n;
}
Abstract_Client* Clienti::operator[](const Iteratore& i) const{
    if(i.n) return (i.n)->cliente;
    return 0;
}

//Rimozione dal contenitore
//ritorna l'iteratore che punta all' oggetto che segue il nodo eliminato
Clienti::Iteratore Clienti::eliminaAScelta(const Iteratore& i){
    Iteratore aux; aux.n=0;
    if(i.n){
        Nodo* precedente = i.n->prev;
        Nodo* successivo = i.n->next;
        delete i.n;
        //ho rimosso l'unico nodo e inizio e fine ora valgono 0
        if(!precedente && !successivo) { inizio = 0; fine = 0; }
        //se ho rimosso il nodo iniziale allora inizio punta all' ex secondo nodo
        else if(!precedente) { inizio = successivo; inizio->prev = 0; aux.n=inizio; }
        //se ho rimosso il nodo finale allora fine punta all' ex penultimo nodo
        else if (!successivo) { fine = precedente; fine->next = 0; aux.n=0; }
        //ho rimosso un nodo "centrale" quindi sistemo la lista
        else { precedente->next = successivo; successivo->prev = precedente; aux.n=successivo;}
    }
    return aux;
}
//numero di clienti nel contenitore
int Clienti::size() const {
    Nodo* temp = 0;
    temp = inizio;
    int ritorna = 0;
    while(temp){
        ++ritorna;
        temp = temp->next;
    }
    return ritorna;
}

//Aggiunta in coda al contenitore

void Clienti::pushBack(Abstract_Client* s){
    if(s){
        Nodo* temp = new Nodo(s,fine,0);
        if(!fine && !inizio){
            fine = temp;
            inizio = temp;
        }
        else{
            fine->next = temp;
            fine = temp;
        }
    }
}
