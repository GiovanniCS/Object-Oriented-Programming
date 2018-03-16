#include "aggiungi_nuovo_utente.h"
#include "utenti.h"

#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QLabel>


aggiungiNuovoUtente::aggiungiNuovoUtente(QWidget* parent, Utenti* u):QDialog(parent), utenti(u){
    setWindowTitle("Inserimento nuovo utente");
    setModal(true);
    setFixedSize(230,250);
    QVBoxLayout* verticale = new QVBoxLayout();

    intro = new QLabel("Compila i dati del nuovo \nutente e clicca su Inserisci!",this);
    intro->setAlignment(Qt::AlignCenter);

    tipo = new QComboBox(this);
    tipo->insertItem(0,"amministratore");
    tipo->insertItem(1,"premium");
    tipo->insertItem(2,"base");
    tipo->setCurrentIndex(0);

    QHBoxLayout* userlay = new QHBoxLayout();
    QLabel* userLabel = new QLabel("Username");
    userEdit = new QLineEdit(this);
    userlay->addWidget(userLabel);
    userlay->addWidget(userEdit);

    QHBoxLayout* passwordlay = new QHBoxLayout();
    QLabel* passLabel = new QLabel("Password");
    passEdit = new QLineEdit(this);
    passwordlay->addWidget(passLabel);
    passwordlay->addWidget(passEdit);

    insert = new QPushButton("Insersci",this);
    connect(insert,SIGNAL(clicked()),this,SLOT(verificaEinserisci()));

    verticale->addWidget(intro);
    verticale->addWidget(tipo);
    verticale->addLayout(userlay);
    verticale->addLayout(passwordlay);
    verticale->addWidget(insert);
    setLayout(verticale);

    connect(this,SIGNAL(finito()),this,SLOT(close()));
}
//verifica e inserisci si assicura che tutti i campi siano compilati e demanda all'oggetto di tipo Utenti
//la costruzione del utente appropriato
void aggiungiNuovoUtente::verificaEinserisci(){
    QString user(userEdit->text());
    QString password(passEdit->text());
    QString t(tipo->currentText());
    if(user.toStdString()!="" && password.toStdString()!=""){
        utenti->aggiungi(t.toStdString(),user.toStdString(),password.toStdString());
        //l'emissione del segnale finito() provoca il refresh della tabella dei clienti e fa in modo che la
        //mainwindow possa tener traccia dei cambiamenti al contenitore non ancora salvati su file
        emit finito();
    }
    else{
        intro->setStyleSheet("color: red");
        intro->setText("Non lasciare nessun\ncampo vuoto!");
    }
}
