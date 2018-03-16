#include "contenitore_servizi.h"

//costruzione e distruzione di Servizio
Contenitore_Servizi::Servizio::Servizio(Servizio_astratto* sa, Servizio* n): s(sa), next(n) {}
Contenitore_Servizi::Servizio::~Servizio(){delete s;}

//costruzione e distruzione profonda di Contenitore_Servizi
Contenitore_Servizi::Contenitore_Servizi():inizio(0) {}
Contenitore_Servizi::~Contenitore_Servizi(){ elimina(inizio); }
void Contenitore_Servizi::elimina(Servizio* s){
    if(s)   elimina(s->next);
    else	return;
    delete s;
}
//ritorna il totale pagato di tutti i servizi usufruiti dal cliente
double Contenitore_Servizi::calcolaTotale() const{
    Servizio* temp = inizio;
    double tot=0;
    while(temp){
        tot += temp->s->getCosto();
        temp = temp->next;
    }
    return tot;
}
void Contenitore_Servizi::aggiungi(Servizio_astratto* s){
    if(!inizio){
        inizio = new Servizio(s);
        return;
    }
    else{
        Servizio* temp = inizio;
        while(temp->next)	temp = temp->next;
        temp->next = new Servizio(s);
    }/*
    //Sarebbe possibile l'inserimento in testa:
    Servizio* n = inizio;
    inizio = new Servizio(s,n);
    //Ma invertirebbe l'ordine dei servizi rispetto a come compaiono nell'xml
    */
}
//ritorna un QString con la lista formattata dei servizi
QString Contenitore_Servizi::stampaServizi() const{
    Servizio* temp = inizio;
    QString stringa = QString::fromStdString("\nLISTA SERVIZI:\n\n");
    while(temp){
        (temp->s->getData()).printData(stringa);
        stringa = stringa + QString::fromStdString("      ") + QString::fromStdString(temp->s->getNome()) + QString::fromStdString("\n\n");
        temp = temp->next;
    }
    return stringa;
}
//Numero di servizi contenuti
unsigned int Contenitore_Servizi::size() const{
    Servizio* temp = inizio;
    unsigned int dim = 0;
    while(temp){
        ++dim; temp = temp->next;
    }
    return dim;
}
//leggiServizio() legge l'i-esimo servizio del cliente, è usato ad es. nel salvataggio del contenitore su file
void Contenitore_Servizi::leggiServizio(unsigned int i, Data & d, std::string & tipo, std::string & opzionale) const{
    Servizio* temp = inizio;
    while(i>1&&temp){
        temp = temp->next;
        --i;
    }
    Servizio_astratto* s = temp->s;
    s->getNomeS(tipo,opzionale);
    d = s->getData();

}
