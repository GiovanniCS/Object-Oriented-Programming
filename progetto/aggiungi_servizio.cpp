#include "aggiungi_servizio.h"
#include "spa_client.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QPushButton>

aggiungiServizio::aggiungiServizio(QWidget* parent, Abstract_Client* c): QDialog(parent), cliente(c){
    setWindowTitle("Aggiungi un servizio");
    setModal(true);
    setFixedSize(400,130);
    QHBoxLayout* primo = new QHBoxLayout();
    QHBoxLayout* secondo = new QHBoxLayout();
    QVBoxLayout* layout = new QVBoxLayout();
    data = new QDateTimeEdit();
    data->setCalendarPopup(true);
    data->setMinimumDate(QDate(2017,1,1));
    secondo->addWidget(data);

    tipo = new QComboBox(this);
    tipo->insertItem(0,"Massaggio");
    tipo->insertItem(1,"Bagno Turco");
    tipo->insertItem(2,"Idromassaggio");
    tipo->insertItem(3,"Sauna");
    tipo->insertItem(4,"Piscina");
    tipo->insertItem(5,"Palestra");
    tipo->setCurrentIndex(0);
    connect(tipo,SIGNAL(activated(int)),this,SLOT(disableEdit(int)));
    primo->addWidget(tipo);

    lab = new QLabel("Inserisci il tipo",this);
    primo->addWidget(lab);
    edit = new QLineEdit(this);
    primo->addWidget(edit);



    QPushButton* inserisci = new QPushButton("Inserisci",this);
    connect(inserisci,SIGNAL(clicked()),this,SLOT(inserisci()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(close()));
    secondo->addWidget(inserisci);

    layout->addLayout(primo);
    layout->addLayout(secondo);
    setLayout(layout);
}
void aggiungiServizio::disableEdit(int i){
    if(i == 1 || i == 2 || i == 3 || i == 4 || i == 5){
        lab->setDisabled(true);
        edit->setDisabled(true);
    }
    else{
        lab->setDisabled(false);
        edit->setDisabled(false);
    }
}
//inserisci si occupa di creare una data e delega al cliente ,opportunamente convertito a Spa_Client,
//la costruzione e relativa aggiunta del nuovo servizio
void aggiungiServizio::inserisci(){
    QString t(tipo->currentText());
    int m = data->time().minute() , o = data->time().hour() ,
            g = data->date().day() , me = data->date().month(),
            a = data->date().year();
    Spa_Client* cl = dynamic_cast<Spa_Client*>(cliente);
    if(t.toStdString() == "Massaggio"){
        QString nome(edit->text());
        cl->nuovo_Servizio(Data(m,o,g,me,a),"massaggio",nome.toStdString());
    }
    else if(t.toStdString() == "Bagno Turco"){
        cl->nuovo_Servizio(Data(m,o,g,me,a),"bagnoturco");
    }
    else if (t.toStdString() == "Idromassaggio"){
        cl->nuovo_Servizio(Data(m,o,g,me,a),"idromassaggio");
    }
    else if (t.toStdString() == "Sauna"){
        cl->nuovo_Servizio(Data(m,o,g,me,a),"sauna");
    }
    else if (t.toStdString() == "Piscina"){
        cl->nuovo_Servizio(Data(m,o,g,me,a),"piscina");
    }
    else if (t.toStdString() == "Palestra"){
        cl->nuovo_Servizio(Data(m,o,g,me,a),"palestra");
    }
    //l'emissione del segnale daSalvare() permette alla mainwindow di tener traccia dei cambiamenti al contenitore non ancora salvati su file
    emit daSalvare();
}
