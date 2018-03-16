#include "tab_widget_premium.h"
#include "tabella_clienti_no_bottoni.h"
#include "clienti.h"
#include "ricerca_clienti.h"

TabWidgetPremium::TabWidgetPremium(Clienti * c, QWidget * parent): QTabWidget(parent), clienti(c){
    //accesso in sola lettura dei clienti per l'utente premium
    tabellaClientiNoButtottoni* widgetClienti = new tabellaClientiNoButtottoni(this,clienti);
    //tab per la ricerca (basata su 3 parametri) tra i clienti.
    widgetRicerca = new ricercaClienti(this,clienti);
    addTab(widgetClienti,"Clienti");
    addTab(widgetRicerca,"Ricerca");
}
