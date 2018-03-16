#include "dettagli_cliente.h"
#include "aggiungi_servizio.h"
#include "aggiungi_scontrino.h"
#include "hotel_client.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QHBoxLayout>

dettagliCliente::dettagliCliente(QWidget* parent, Abstract_Client *c):QDialog(parent),cliente(c){
    setWindowTitle("Consulta e modifica i dati del cliente");
    setModal(true);
    setFixedSize(600,500);

    //imposto un layout a dettagliCliente, e ci aggiungo la scrollarea
    QScrollArea *scroll = new QScrollArea();
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    QHBoxLayout *dialog_layout = new QHBoxLayout(this);
    dialog_layout->addWidget(scroll);
    setLayout(dialog_layout);

    //unico figlio della scrollarea è viewport che fa da "pannello" su cui aggiungere i vari widget
    QWidget *viewport = new QWidget(this);
    scroll->setWidget(viewport);
    scroll->setWidgetResizable(true);

    QVBoxLayout *l = new QVBoxLayout(viewport);
    viewport->setLayout(l);

    //Nome
    QString snome(QString::fromStdString(c->getNome()));
    QHBoxLayout* nomelay = new QHBoxLayout();
    QLabel* nome = new QLabel("Nome:",this);
    nomeedit = new QLineEdit(snome,this);
    nomelay->addWidget(nome);
    nomelay->addWidget(nomeedit);
    nomelay->addSpacing(170);

    //pulsante per aggiornare i dati modificati (aggiornamento solo in memoria e non su file)
    QPushButton* aggiorna = new QPushButton("Aggiorna",this);
    connect(aggiorna,SIGNAL(clicked()),this,SLOT(aggiornaCliente()));
    nomelay->addWidget(aggiorna);

    //cognome
    QString scogn(QString::fromStdString(c->getCognome()));
    QHBoxLayout* cognomelay = new QHBoxLayout();
    QLabel* cognome = new QLabel("Cognome:",this);
    cognomeedit = new QLineEdit(scogn,this);
    cognomelay->addWidget(cognome);
    cognomelay->addWidget(cognomeedit);
    cognomelay->addSpacing(260);


    //codice fiscale
    QString scod(QString::fromStdString(c->getCodiceFiscale()));
    QHBoxLayout* codicelay = new QHBoxLayout();
    QLabel* codice = new QLabel("Codice fiscale:",this);
    codiceedit = new QLineEdit(scod,this);
    codicelay->addWidget(codice);
    codicelay->addWidget(codiceedit);
    codicelay->addSpacing(260);


    //numero
    QString snum(QString::fromStdString(c->getPuntIndirizzo()->getNumeroCivico()));
    QHBoxLayout* numerolay = new QHBoxLayout();
    QLabel* numero = new QLabel("Numero:",this);
    numeroedit = new QLineEdit(snum,this);
    numerolay->addWidget(numero);
    numerolay->addWidget(numeroedit);
    numerolay->addSpacing(260);

    //via
    QString svia(QString::fromStdString(c->getPuntIndirizzo()->getVia()));
    QHBoxLayout* vialay = new QHBoxLayout();
    QLabel* via = new QLabel("Via:",this);
    viaedit = new QLineEdit(svia,this);
    vialay->addWidget(via);
    vialay->addWidget(viaedit);
    vialay->addSpacing(260);

    //citta
    QString scitta(QString::fromStdString(c->getPuntIndirizzo()->getCitta()));
    QHBoxLayout* cittalay = new QHBoxLayout();
    QLabel* citta = new QLabel("Città:",this);
    cittaedit = new QLineEdit(scitta,this);
    cittalay->addWidget(citta);
    cittalay->addWidget(cittaedit);
    cittalay->addSpacing(260);

    //provincia
    QString sprov(QString::fromStdString(c->getPuntIndirizzo()->getProvincia()));
    QHBoxLayout* provincialay = new QHBoxLayout();
    QLabel* provincia = new QLabel("Provincia:",this);
    provinciaedit = new QLineEdit(sprov,this);
    provincialay->addWidget(provincia);
    provincialay->addWidget(provinciaedit);
    provincialay->addSpacing(260);


    //stato
    QString stat(QString::fromStdString(c->getPuntIndirizzo()->getStato()));
    QHBoxLayout* statolay = new QHBoxLayout();
    QLabel* stato = new QLabel("Stato:",this);
    statoedit = new QLineEdit(stat,this);
    statolay->addWidget(stato);
    statolay->addWidget(statoedit);
    statolay->addSpacing(260);


    //aggiungo al layout di viewport tutti gli elementi di visualizzazione / modifica
    l->addLayout(nomelay);
    l->addLayout(cognomelay);
    l->addLayout(codicelay);
    l->addLayout(numerolay);
    l->addLayout(vialay);
    l->addLayout(cittalay);
    l->addLayout(provincialay);
    l->addLayout(statolay);

    QHBoxLayout* bottonilay = new QHBoxLayout();
    QPushButton* scontrino;
    QPushButton* servizio;
    QLabel* tipo;
    errore= new QLabel("",this);
    errore->setMaximumHeight(20);
    l->addWidget(errore);

    //in base al tipo di cliente aggiungo ulteriori elementi al layout
    if(dynamic_cast<Hotel_Client*>(c)){
        Hotel_Client* hotcli = dynamic_cast<Hotel_Client*>(cliente);
        QString scon(hotcli->stampaScontrini());
        QString serv(hotcli->stampaServizi());

        scontrino = new QPushButton("Aggiungi scontrino");
        servizio = new QPushButton("Aggiungi servizio");
        connect(servizio,SIGNAL(clicked()),this,SLOT(aggiungiServ()));
        connect(scontrino,SIGNAL(clicked()),this,SLOT(aggiungiScontr()));
        bottonilay->addWidget(scontrino);
        bottonilay->addWidget(servizio);
        QString segnaturaCliente("Cliente d'Hotel!\nCheck-in: ");
        hotcli->getIn().printData(segnaturaCliente);
        segnaturaCliente += QString::fromStdString("\nCheck-out: ");
        hotcli->getOut().printData(segnaturaCliente);

        tipo = new QLabel(segnaturaCliente);
        tipo->setMaximumHeight(100);
        l->addWidget(tipo);
        l->addLayout(bottonilay);
        QLabel * lsc= new QLabel(scon,this);//desctizione di tutti gli scontrini
        l->addWidget(lsc);
        QLabel * lsr= new QLabel(serv,this);//descrizione di tutti i servizi
        l->addWidget(lsr);
        QString xd("Prezzo totale pagato:    ");
        xd = xd + QString::number(cliente->costo_totale());
        QLabel* totale = new QLabel(xd,this);
        l->addWidget(totale);

    }
    else if(dynamic_cast<Restaurant_Client*>(c)){
        Restaurant_Client* rescli = dynamic_cast<Restaurant_Client*>(c);
        QString scon(rescli->stampaScontrini());
        scontrino = new QPushButton("Aggiungi scontrino");
        connect(scontrino,SIGNAL(clicked()),this,SLOT(aggiungiScontr()));
        bottonilay->addWidget(scontrino);
        tipo = new QLabel("Cliente di Ristorante!");
        tipo->setMaximumHeight(20);
        l->addWidget(tipo);
        l->addLayout(bottonilay);
        QLabel * lsc= new QLabel(scon,this);
        l->addWidget(lsc);
        QString xd("Prezzo totale pagato:    ");
        xd = xd + QString::number(cliente->costo_totale());
        QLabel* totale = new QLabel(xd,this);
        l->addWidget(totale);
    }
    else if(dynamic_cast<Spa_Client*>(c)){
        Spa_Client* spasco = dynamic_cast<Spa_Client*>(c);
        QString scon(spasco->stampaServizi());
        servizio = new QPushButton("Aggiungi servizio");
        connect(servizio,SIGNAL(clicked()),this,SLOT(aggiungiServ()));
        bottonilay->addWidget(servizio);
        tipo = new QLabel("Cliente della Spa!");
        tipo->setMaximumHeight(20);
        l->addWidget(tipo);
        l->addLayout(bottonilay);
        QLabel * lsr= new QLabel(scon,this);
        l->addWidget(lsr);
        QString xd("Prezzo totale pagato:    ");
        xd = xd + QString::number(cliente->costo_totale()) + QString::fromStdString("   euro\n");
        QLabel* totale = new QLabel(xd,this);
        l->addWidget(totale);
    }

    show();
}
//raccolgo le modifiche, controllo che tutti i campi siano compilati
//e modifico il cliente nel contenitore
void dettagliCliente::aggiornaCliente(){
    QString no(nomeedit->text());
    QString co(cognomeedit->text());
    QString cod(codiceedit->text());
    QString vi(viaedit->text());
    QString nu(numeroedit->text());
    QString cit(cittaedit->text());
    QString pro(provinciaedit->text());
    QString stat(statoedit->text());
    if(no.toStdString()!="" && co.toStdString()!="" && cod.toStdString()!=""
            && vi.toStdString()!="" && nu.toStdString()!="" && cit.toStdString()!="" && pro.toStdString()!="" && stat.toStdString()!=""){
        errore->setText("");
        cliente->setNome(no.toStdString());
        cliente->setCognome(co.toStdString());
        cliente->setCodiceFiscale(cod.toStdString());
        cliente->setIndirizzo(nu.toStdString(),vi.toStdString(),cit.toStdString(),pro.toStdString(),stat.toStdString());
        //aggiorno la tabella dei clienti con i dati appena inseriti e comunico alla mainwindow che esistono cambiamenti al
        //contenitore non ancora salvati su file
        emit daSalvare();
        emit refresh();
    }
    else{
        errore->setStyleSheet("color: red");
        errore->setText("Non lasciare campi vuoti!");
    }
}
//permette di aggiungere uno scontrino tramite una nuova finestra di dialogo premendo sul bottone "nuovo Scontrino"
void dettagliCliente::aggiungiScontr(){
    aggiungiScontrino* a= new aggiungiScontrino(this,cliente);
    connect(a,SIGNAL(daSalvare()),this,SIGNAL(daSalvare()));
    a->show();
}
//permette di aggiungere un servizio tramite una nuova finestra di dialogo premendo sul bottone "nuovo Servizio"
void dettagliCliente::aggiungiServ(){
    aggiungiServizio* a = new aggiungiServizio(this,cliente);
    connect(a,SIGNAL(daSalvare()),this,SIGNAL(daSalvare()));
    a->show();
}
