#include "utenti.h"
#include <QString>
using std::string;

Utenti::Nodo::Nodo(Utente t, Nodo * tt):u(t), next(tt){}

void Utenti::el(Nodo* n){
    if(!n) return;
    el(n->next);
    delete n;
}
//distruzione profonda dell'oggetto
Utenti::~Utenti(){
    if(inizio)  el(inizio);
}
Utenti::Utenti():inizio(0){}

void Utenti::aggiungi(string tipo, string user, string pass){
    Nodo* temp = new Nodo(Utente(user,pass,tipo));
    if(!inizio) inizio = temp;
    else{
        Nodo* temp2 = inizio;
        while(temp2->next) temp2 = temp2->next;
        temp2->next= temp;
    }
}
int Utenti::rimuovi(int s){
    //ritorna 0 se non esiste l'utente, 1 se è stato rimosso, e -1 se si è tentato di rimuovere l'unico amministratore rimasto
    Nodo* temp = inizio;
    Nodo* prec=0;
    for(int a=0;a<s && temp;++a) {
        prec = temp;
        temp = temp->next;
    }
    //se sono andato oltre ai nodi presenti e non sono arrivato all'indice che volevo ritorno 0.
    //caso comunque non possibile.
    if(!temp)  return 0;
    //se lo username corrisponde AND ( o non è un amministratore, oppure lo è e non è l'unico )
    else if(((temp->u.getTipo() == "amministratore") && contaAmministratori() <= 1 )) return -1;

    else{
        if(!prec){
            inizio = temp->next;
            delete temp;
        }
        else{
            prec->next = temp->next;
            delete temp;
        }
        return 1;
    }
}

unsigned int Utenti::size() const{
    Nodo* temp = inizio; int elementi = 0;
    while(temp){
        ++elementi;
        temp = temp->next;
    }
    return elementi;
}
void Utenti::leggiUtente(unsigned int i ,string& nome, string& pass, string& tipo) const{
    Nodo* temp = inizio;
    //non servono controlli sul puntatore, in quanto chiedo la lettura dell'i-esimo cliente solo quando l'indice è minore della
    //dimensione del contenitore
    while(i>1){
        temp = temp ->next;
        --i;
    }
    nome = (temp->u).getUsername();
    pass = (temp->u).getPassword();
    tipo = (temp->u).getTipo();
}
//aggiorna le informazioni relative all'i-esimo utente
void Utenti::salvaUtente(unsigned int i ,string nome, string pass, string tipo){
    Nodo* temp = inizio;
    while(i>1){
        temp = temp ->next;
        --i;
    }
    (temp->u).setUsername(nome);
    (temp->u).setPassword(pass);
    (temp->u).setTipo(tipo);
}
//controlla che quello specifico cliente sia presente nel contenitore
bool Utenti::esiteUtente(string tipo, string nome, string password){
    Nodo* temp = inizio;
    bool esiste = false;
    while(temp && !esiste){
        if(((temp->u).getTipo() == tipo) &&((temp->u).getUsername() == nome) && ((temp->u).getPassword() == password) ){
            esiste = true;
        }
        else
            temp = temp->next;
    }
    return esiste;
}

Utente* Utenti::operator[](unsigned int i){
    if(i<size()){
        Nodo* temp = inizio;
        while(i>0)  {temp = temp->next; --i;}
        return &(temp->u);
    }else
        return 0;
}
//conta quanti amministratori sono presenti nel contenitore
unsigned int Utenti::contaAmministratori() const{
    Nodo* temp = inizio;
    unsigned int conta =0;
    while(temp){
        if((temp->u).getTipo() == "amministratore")
            ++conta;
        temp = temp->next;
    }
    return conta;
}
