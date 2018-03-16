#include "lista_scontrini.h"

Lista_Scontrini::Scontrino::Scontrino(const Data& d, int pers, double tot, Scontrino* n): data(d), num_persone(pers), totale(tot), next(n){}

Lista_Scontrini::Lista_Scontrini():inizio(0){}
//distruzione profonda
Lista_Scontrini::~Lista_Scontrini(){ elimina(inizio); }

void Lista_Scontrini::elimina(Scontrino* s){
     if(s)   elimina(s->next);
     else	return;
     delete s;
}

void Lista_Scontrini::aggiungi(const Data& d, int i, double db){
    if(!inizio){
        inizio = new Scontrino(d,i,db);
        return;
    }
    else{
        Scontrino* temp = inizio;
        while(temp->next)	temp = temp->next;
        temp->next = new Scontrino(d,i,db);
    }/*
    //Sarebbe possibile l'inserimento in testa:
    Scontrino* temp = inizio;
    inizio = new Scontrino(d,i,db,temp);
    //Ma invertirebbe l'ordine degli scontrini rispetto a come compaiono nell'xml
    */
}

double Lista_Scontrini::calcolaTotale() const{
    Scontrino* in = inizio;
    double tot=0;
    while(in){
        tot += in->totale;
        in = in->next;
    }
    return tot;
}
//ritorna un QString con la lista formattata degli scontrini
QString Lista_Scontrini::stampaScontrini() const{
    Scontrino* temp = inizio;
    QString stringa = QString::fromStdString("\nLISTA SCONTRINI:\n\n");
    while(temp){
        (temp->data).printData(stringa);
        stringa = stringa + QString::fromStdString("\nNumero Persone: ") + QString::number(temp->num_persone) + QString::fromStdString("   ") + QString::fromStdString(" Totale: ") + QString::number(temp->totale) + QString::fromStdString("  euro\n");
        temp=temp->next;
        stringa = stringa + QString::fromStdString("\n");
    }
    return stringa;
}

unsigned int Lista_Scontrini::size() const{
    unsigned int dim = 0;
    Scontrino* temp = inizio;
    while(temp){
        ++dim; temp = temp->next;
    }
    return dim;
}
//leggiScontrino() legge l'i-esimo scontrino del cliente, è usato ad es. nel salvataggio del contenitore su file
void Lista_Scontrini::leggiScontrino(unsigned int n ,Data& d,int& g, double& s )const{
    Scontrino* temp = inizio;
    while(n>1){
        temp = temp->next;
        --n;
    }
    d = temp->data;
    g = temp ->num_persone;
    s = temp->totale;
}
