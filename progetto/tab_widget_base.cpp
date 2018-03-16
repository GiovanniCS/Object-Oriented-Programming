#include "tab_widget_base.h"
#include "tabella_clienti_no_bottoni.h"
#include "clienti.h"

TabWidgetBase::TabWidgetBase(Clienti* c,QWidget* parent):QTabWidget(parent),clienti(c){
    //unico tab a disposizione per gli utenti base
    tabellaClientiNoButtottoni* widgetClienti = new tabellaClientiNoButtottoni(this,clienti);
    addTab(widgetClienti,"Clienti");
}
