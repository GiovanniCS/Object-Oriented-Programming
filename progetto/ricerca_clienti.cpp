#include "ricerca_clienti.h"
#include "query_object.h"
#include "abstract_client.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QTableWidget>
#include <QStringList>
#include <QHeaderView>
#include <QLabel>
#include <QString>

ricercaClienti::ricercaClienti(QWidget * parent, Clienti * c): QWidget(parent), clienti(c),queryobject(new queryObject()){
    QHBoxLayout* hor = new QHBoxLayout();
    QVBoxLayout* ver = new QVBoxLayout();
    tipo = new QComboBox(this);
    QLabel* tutti= new QLabel("Cerca tutti i ",this);
    tipo->insertItem(0,"Clienti");
    tipo->insertItem(1,"Cliente di Hotel");
    tipo->insertItem(2,"Cliente di Spa");
    tipo->insertItem(3,"Cliente di Ristorante");
    tipo->setCurrentIndex(0);
    hor->addWidget(tutti);
    hor->addWidget(tipo);
    QLabel* spesa= new QLabel("con spesa maggiore di: ",this);
    QLabel* euro= new QLabel("€,  ",this);
    spinspesa = new QSpinBox(this);
    spinspesa->setMaximum(500000);
    hor->addWidget(spesa);
    hor->addWidget(spinspesa);
    hor->addWidget(euro);

    QLabel* provenienti= new QLabel("provenienti da: ",this);
    dove = new QComboBox(this);
    dove->insertItem(0,"Veneto");
    dove->insertItem(1,"Italia");
    dove->insertItem(2,"Tutto il mondo");
    hor->addWidget(provenienti);
    hor->addWidget((dove));
    hor->addStretch();

    QPushButton* cerca = new QPushButton("Cerca",this);
    connect(cerca,SIGNAL(clicked()),this,SLOT(query()));
    hor->addWidget(cerca);

    ver->addLayout(hor);

    tabella = new QTableWidget(this);
    tabella->setColumnCount(4);
    QStringList intestazione;
    intestazione<<"Nome"<<"Cognome"<<"Codice Fiscale"<<"Indirizzo";
    tabella->setHorizontalHeaderLabels(intestazione);
    for(int i=0; i<4; ++i)
        tabella->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    ver->addWidget(tabella);
    setLayout(ver);
}

void ricercaClienti::query(){
    QString chi(tipo->currentText());
    int quanto(spinspesa->value());
    QString sdove(dove->currentText());
    std::vector<Abstract_Client*> v;
    queryobject->query(v,clienti,chi.toStdString(),quanto,sdove.toStdString());
    for(int i=tabella->rowCount();i>0;i--)
        tabella->removeRow(i-1);
    std::vector<Abstract_Client*>::iterator it = v.begin();
    for(int i =0; it != v.end(); ++it,++i){
        tabella->insertRow(i);
        QString nome(QString::fromStdString((*it)->getNome()));
        QString cognome(QString::fromStdString((*it)->getCognome()));
        QString codice(QString::fromStdString((*it)->getCodiceFiscale()));
        QString indirizzo(QString::fromStdString((*it)->getIndirizzo()));
        tabella->setCellWidget(i,0,new QLabel(nome,this));
        tabella->setCellWidget(i,1,new QLabel(cognome,this));
        tabella->setCellWidget(i,2,new QLabel(codice,this));
        tabella->setCellWidget(i,3,new QLabel(indirizzo,this));
    }

}
