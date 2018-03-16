#include "tabella_clienti_no_bottoni.h"
#include "clienti.h"
#include <QStringList>
#include <QHeaderView>
#include <QLabel>
#include <QString>

tabellaClientiNoButtottoni::tabellaClientiNoButtottoni(QWidget* parent, Clienti* c):QTableWidget(parent),clienti(c){
    setColumnCount(4);
    QStringList intestazione;
    intestazione<<"Nome"<<"Cognome"<<"Codice Fiscale"<<"Indirizzo";
    setHorizontalHeaderLabels(intestazione);

    for(int i=2; i<4; ++i)
        horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);

    Clienti::Iteratore it = clienti->begin();
    for(int i=0;it != clienti->end();++it,++i){
        insertRow(i);
        QString nome(QString::fromStdString((*clienti)[it]->getNome()));
        QString cognome(QString::fromStdString((*clienti)[it]->getCognome()));
        QString codice(QString::fromStdString((*clienti)[it]->getCodiceFiscale()));
        QString indirizzo(QString::fromStdString((*clienti)[it]->getIndirizzo()));
        setCellWidget(i,0,new QLabel(nome,this));
        setCellWidget(i,1,new QLabel(cognome,this));
        setCellWidget(i,2,new QLabel(codice,this));
        setCellWidget(i,3,new QLabel(indirizzo,this));
    }

}
