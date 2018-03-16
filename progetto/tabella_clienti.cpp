#include <QStringList>
#include <QHeaderView>
#include <QLabel>
#include <QString>
#include <QPushButton>

#include "tabella_clienti.h"
#include "clienti.h"
#include "count_button.h"
#include "dettagli_cliente.h"

tabellaClienti::tabellaClienti(QWidget* parent, Clienti* c):QTableWidget(parent),clienti(c){
    setColumnCount(6);
    QStringList intestazione;
    intestazione<<"Nome"<<"Cognome"<<"Codice Fiscale"<<"Indirizzo"<<"-------"<<"-----------";
    setHorizontalHeaderLabels(intestazione);

    for(int i=2; i<4; ++i)
        horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    riDisegna();
}

//delega all'oggetto di tipo Clienti la rimozione del cliente scelto
void tabellaClienti::elimina(int indice){
    Clienti::Iteratore it = clienti->begin();
    for(int j=0;j<indice;++j)
        ++it;
    clienti->eliminaAScelta(it);
    emit daSalvare();
    riDisegna();
}
//rimuove (se presenti) le vecchie righe della tabella e ne aggiunge di nuove, in modo che siano coerenti con l'effettivo
//contenuto del contenitore di tipo Clienti
void tabellaClienti::riDisegna(){
    for(int i=rowCount();i>0;i--)
        removeRow(i-1);
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
        countButton* open = new countButton("Apri",this,i);
        setCellWidget(i,4,open);
        connect(open,SIGNAL(cliccato(int)),this,SLOT(apri(int)));
        countButton* erease = new countButton("Elimina",this,i);
        connect(erease,SIGNAL(cliccato(int)),this,SLOT(elimina(int)));
        setCellWidget(i,5,erease);
    }
}
//apre una finestra di dialogo che permette la consultazione dettagliata del cliente e alcune funzionalità di modifica
void tabellaClienti::apri(int indice){
    Clienti::Iteratore it = clienti->begin();
    for(int g=0;g<indice;++g)   ++it;
    dettagliCliente* dettagli = new dettagliCliente(this,(*clienti)[it]);
    connect(dettagli,SIGNAL(refresh()),this,SLOT(riDisegna()));
    connect(dettagli,SIGNAL(daSalvare()),this,SIGNAL(daSalvare()));
    dettagli->show();
}
