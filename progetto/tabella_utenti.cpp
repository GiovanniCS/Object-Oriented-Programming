#include "tabella_utenti.h"
#include "count_button.h"
#include "ultimo_amministratore.h"

#include <QStringList>
#include <QHeaderView>
#include <QString>
#include "utenti.h"
#include <QComboBox>
#include <QLineEdit>


tabellaUtenti::tabellaUtenti(QWidget* parent, Utenti* u):QTableWidget(parent),utenti(u){
    setColumnCount(5);
    QStringList intestazione;
    intestazione<<"Tipo"<<"Username"<<"Password"<<"-----------"<<"refresh";
    setHorizontalHeaderLabels(intestazione);
    horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    riDisegna();
}
//delega all'oggetto di tipo Utenti la rimozione dell'utente scelto
void tabellaUtenti::elimina(int indice){
    int risultato = utenti->rimuovi(indice);
    if(risultato == -1){
        ultimoAmministratore* ultimo = new ultimoAmministratore(this);
        ultimo->show();
    }
    else if(risultato == 1){
        riDisegna();
        emit daSalvare();
    }
}
//raccoglie i nuovi dati inseriti relativi all'utente e li fa salvare da utenti
void tabellaUtenti::aggiorna(int indice){
    QComboBox* tip = static_cast<QComboBox*>(cellWidget(indice,0));
    QLineEdit* us = static_cast<QLineEdit*>(cellWidget(indice,1));
    QLineEdit* pas = static_cast<QLineEdit*>(cellWidget(indice,2));
    QString uss = us->text();
    QString pass = pas->text();
    QString tips= tip->currentText();
    if(pass.toStdString() != "" && uss.toStdString() != "" ){
        utenti->salvaUtente(indice+1,uss.toStdString(),pass.toStdString(),tips.toStdString());
        emit daSalvare();
    }
}
//rimuove (se presenti) le vecchie righe della tabella e ne aggiunge di nuove, in modo che siano coerenti con l'effettivo
//contenuto del contenitore di tipo Utenti
void tabellaUtenti::riDisegna(){
    for(int i=rowCount();i>0;i--)
        removeRow(i-1);

    for(unsigned int j=0; j < utenti->size(); ++j){
        insertRow(j);
        std::string user;
        std::string pass;
        std::string tip;
        utenti->leggiUtente(j+1,user,pass,tip);
        QString username(QString::fromStdString(user));
        QString password(QString::fromStdString(pass));
        QString tipo(QString::fromStdString(tip));

        QComboBox* combo = new QComboBox(this);
        combo->insertItem(0,"amministratore");
        combo->insertItem(1,"premium");
        combo->insertItem(2,"base");
        if(tipo == "premium")
            combo->setCurrentIndex(1);
        else if (tipo == "base")
            combo->setCurrentIndex(2);
        else
            combo->setCurrentIndex(0);

        setCellWidget(j,0,combo);
        setCellWidget(j,1,new QLineEdit(username,this));
        setCellWidget(j,2,new QLineEdit(password,this));
        countButton* erease = new countButton("Elimina",this,j);
        setCellWidget(j,3,erease);
        connect(erease,SIGNAL(cliccato(int)),this,SLOT(elimina(int)));
        countButton* refresh = new countButton("Aggiorna",this,j);
        connect(refresh,SIGNAL(cliccato(int)),this,SLOT(aggiorna(int)));
        setCellWidget(j,4,refresh);
    }
}
