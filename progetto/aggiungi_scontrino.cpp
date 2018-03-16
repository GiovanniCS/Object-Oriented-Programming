#include "aggiungi_scontrino.h"
#include "restaurant_client.h"

#include <QSpinBox>
#include <QLabel>
#include <QDateTimeEdit>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

aggiungiScontrino::aggiungiScontrino(QWidget* parent, Abstract_Client* c):QDialog(parent),cliente(c){
    setWindowTitle("Aggiungi uno scontrino");
    setModal(true);
    setFixedSize(400,130);
    QHBoxLayout* primo = new QHBoxLayout();
    QHBoxLayout* secondo = new QHBoxLayout();
    QVBoxLayout* layout = new QVBoxLayout();

    QLabel* persLabel = new QLabel("N. persone:",this);
    persone = new QSpinBox(this);
    primo->addWidget(persLabel);
    primo->addWidget(persone);

    QLabel* totLabel = new QLabel("Totale: €",this);
    tot = new QDoubleSpinBox(this);
    tot->setMaximum(1500.0);
    primo->addWidget(totLabel);
    primo->addWidget(tot);

    data = new QDateTimeEdit();
    data->setCalendarPopup(true);
    data->setMinimumDate(QDate(2017,1,1));
    secondo->addWidget(data);
    QPushButton* inserisci = new QPushButton("Inserisci",this);
    connect(inserisci,SIGNAL(clicked()),this,SLOT(inserisci()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(close()));
    secondo->addWidget(inserisci);
    layout->addLayout(primo);
    layout->addLayout(secondo);
    setLayout(layout);
}
//inserisci raccoglie dalla Gui i dati inseriti e avendo a disposizione un puntatore al cliente interessato
//ne delega l'aggiunta tramite il metodo nuovo_Scontrino()
void aggiungiScontrino::inserisci(){
    int m = data->time().minute() , o = data->time().hour() ,
            g = data->date().day() , me = data->date().month(),
            a = data->date().year();
    int p(persone->value());
    double t(tot->value());
    Restaurant_Client* cl = dynamic_cast<Restaurant_Client*>(cliente);
    cl->nuovo_Scontrino(Data(m,o,g,me,a),p,t);
    //l'emissione del segnale daSalvare() permette alla mainwindow di tener traccia dei cambiamenti al contenitore non ancora salvati su file
    emit daSalvare();
}
