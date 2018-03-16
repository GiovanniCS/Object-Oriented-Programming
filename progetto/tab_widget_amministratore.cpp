#include "tab_widget_amministratore.h"
#include "ricerca_clienti.h"
#include "tabella_clienti.h"
#include "tabella_utenti.h"
#include "aggiungi_nuovo_utente.h"
#include "aggiungi_nuovo_cliente.h"

TabWidgetAmministratore::TabWidgetAmministratore( Utenti* u, Clienti* c, QWidget* parent):QTabWidget(parent),clienti(c),utenti(u){
    //tab per la visualizzazione / modifica dei clienti
    widgetClienti = new tabellaClienti(this,c);
    connect(widgetClienti,SIGNAL(daSalvare()),this,SIGNAL(daSalvare()));
    //tab per la visualizzazione / modifica degli utenti
    widgetUtenti = new tabellaUtenti(this,u);
    connect(widgetUtenti,SIGNAL(daSalvare()),this,SIGNAL(daSalvare()));
    //tab per la ricerca (basata su 3 parametri) tra i clienti
    widgetRicerca = new ricercaClienti(this,c);

    addTab(widgetClienti,"Clienti");
    addTab(widgetUtenti,"Utenti");
    addTab(widgetRicerca,"Ricerca");
}

void TabWidgetAmministratore::aggiungiUtente(){
    //apri una QDialog e raccogli i dati del nuovo utente
    aggiungiNuovoUtente* a = new aggiungiNuovoUtente(this,utenti);
    a->show();
    connect(a,SIGNAL(finito()),widgetUtenti,SLOT(riDisegna()));
    connect(a,SIGNAL(finito()),this,SIGNAL(daSalvare()));
}
void TabWidgetAmministratore::aggiungiCliente(){
    //apri una QDialog e raccogli i dati del nuovo cliente
    aggiungiNuovoCliente* a = new aggiungiNuovoCliente(this,clienti);
    a->show();
    connect(a,SIGNAL(finito()),widgetClienti,SLOT(riDisegna()));
    connect(a,SIGNAL(finito()),this,SIGNAL(daSalvare()));
}
