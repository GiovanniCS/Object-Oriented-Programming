#include "aggiungi_nuovo_cliente.h"
#include "clienti.h"

#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>


aggiungiNuovoCliente::aggiungiNuovoCliente(QWidget * parent, Clienti * c):QDialog(parent), clienti(c){
    setWindowTitle("Inserimento nuovo cliente");
    setModal(true);
    setFixedSize(270,540);
    QVBoxLayout* verticale = new QVBoxLayout();
    //introduzione della QDialog
    intro = new QLabel("Compila i dati del nuovo \ncliente e clicca su Inserisci!",this);
    intro->setAlignment(Qt::AlignCenter);

    QLabel* tip = new QLabel("Tipo",this);
    tip->setAlignment(Qt::AlignCenter);
    //scelta del tipo di cliente
    tipo = new QComboBox(this);
    tipo->insertItem(0,"Cliente Hotel");
    tipo->insertItem(1,"Cliente Spa");
    tipo->insertItem(2,"Cliente Ristorante");
    tipo->setCurrentIndex(0);
    connect(tipo,SIGNAL(activated(int)),this,SLOT(disableDate(int)));
    //calendario per l'input della data di check-in
    QLabel* in = new QLabel("Check-in");
    indate = new QDateTimeEdit();
    indate->setCalendarPopup(true);
    QDate temp(2017,1,1);
    indate->setMinimumDate(temp);

    QHBoxLayout* inlay = new QHBoxLayout();
    inlay->addWidget(in);
    inlay->addWidget(indate);
    indate->setMinimumWidth(160);
    //calendario per l'input della data di check-out
    QLabel* out = new QLabel("Check-out");
    outdate = new QDateTimeEdit();
    outdate->setCalendarPopup(true);
    outdate->setMinimumDate(temp);

    QHBoxLayout* outlay = new QHBoxLayout();
    outlay->addWidget(out);
    outlay->addWidget(outdate);
    outdate->setMinimumWidth(160);

    QLabel* nome = new QLabel("Nome",this);
    nome->setAlignment(Qt::AlignCenter);
    nomeEdit = new QLineEdit(this);

    QLabel* cognome = new QLabel("Cognome",this);
    cognome->setAlignment(Qt::AlignCenter);
    cognomeEdit = new QLineEdit(this);

    QLabel * codice = new QLabel("Codice fiscale",this);
    codice->setAlignment(Qt::AlignCenter);
    codiceEdit = new QLineEdit(this);

    QLabel* via = new QLabel("Via",this);
    viaEdit = new QLineEdit(this);
    QHBoxLayout* vialay = new QHBoxLayout();
    vialay->addWidget(via);
    vialay->addWidget(viaEdit);

    QLabel* numero = new QLabel("Numero",this);
    numeroEdit = new QLineEdit(this);
    QHBoxLayout* numerolay = new QHBoxLayout();
    numerolay->addWidget(numero);
    numerolay->addWidget(numeroEdit);

    QLabel* citta = new QLabel("Città",this);
    cittaEdit = new QLineEdit(this);
    QHBoxLayout* cittalay = new QHBoxLayout();
    cittalay->addWidget(citta);
    cittalay->addWidget(cittaEdit);

    QLabel* provincia = new QLabel("Provincia",this);
    provinciaEdit = new QLineEdit(this);
    QHBoxLayout* provincialay = new QHBoxLayout();
    provincialay->addWidget(provincia);
    provincialay->addWidget(provinciaEdit);

    QLabel* stato = new QLabel("Stato",this);
    statoEdit = new QLineEdit(this);
    QHBoxLayout* statolay = new QHBoxLayout();
    statolay->addWidget(stato);
    statolay->addWidget(statoEdit);
    //cliccando su Inserisci viene controllato che tutti i campi siano compilati e viene inserito il nuovo cliente
    insert = new QPushButton("Inserisci",this);
    connect(insert,SIGNAL(clicked()),this,SLOT(verificaEinserisci()));

    verticale->addWidget(intro);
    verticale->addWidget(tip);
    verticale->addWidget(tipo);
    verticale->addLayout(inlay);
    verticale->addLayout(outlay);
    verticale->addWidget(nome);
    verticale->addWidget(nomeEdit);
    verticale->addWidget(cognome);
    verticale->addWidget(cognomeEdit);
    verticale->addWidget(codice);
    verticale->addWidget(codiceEdit);
    verticale->addLayout(vialay);
    verticale->addLayout(numerolay);
    verticale->addLayout(cittalay);
    verticale->addLayout(provincialay);
    verticale->addLayout(statolay);
    verticale->addWidget(insert);
    setLayout(verticale);
    //una volta inserito il cliente, la QDialog si chiude
    connect(this,SIGNAL(finito()),this,SLOT(close()));
}
//verifica e inserisci si occupa di costruire e aggiungere al contenitore i nuovi clienti inseriti dall'amministratore
void aggiungiNuovoCliente::verificaEinserisci(){
    QString t(tipo->currentText());
    QString no(nomeEdit->text());
    QString co(cognomeEdit->text());
    QString cod(codiceEdit->text());
    QString vi(viaEdit->text());
    QString nu(numeroEdit->text());
    QString cit(cittaEdit->text());
    QString pro(provinciaEdit->text());
    QString stat(statoEdit->text());
    //se i campi sono tutti compilati si procede con l'inserimento altrimenti compare un messaggio d'avvertimento
    if(t.toStdString()!="" && no.toStdString()!="" && co.toStdString()!="" && cod.toStdString()!=""
            && vi.toStdString()!="" && nu.toStdString()!="" && cit.toStdString()!="" && pro.toStdString()!="" && stat.toStdString()!=""){
        //a seconda del tipo di cliente selezionato si procede alla sua costruzione
        if(t.toStdString() == "Cliente Hotel"){
            int m = indate->time().minute() , o = indate->time().hour() , g = indate->date().day() , me = indate->date().month(), a = indate->date().year();
            int _m = outdate->time().minute(), _o = outdate->time().hour(), _g = outdate->date().day() , _me = outdate->date().month(), _a = outdate->date().year();
            Data checkindate(m,o,g,me,a);
            Data checkoutdate(_m,_o,_g,_me,_a);
            Hotel_Client* ahotel = 0;
            ahotel = new Hotel_Client(no.toStdString(),co.toStdString(),cod.toStdString(),Indirizzo(vi.toStdString(),nu.toStdString(),cit.toStdString(),pro.toStdString(),stat.toStdString()),checkindate,checkoutdate);
            if(ahotel)
                clienti->pushBack(ahotel);
        }
        else if(t.toStdString() == "Cliente Spa"){
            Spa_Client* a = 0;
            a = new Spa_Client(no.toStdString(),co.toStdString(),cod.toStdString(),Indirizzo(vi.toStdString(),nu.toStdString(),cit.toStdString(),pro.toStdString(),stat.toStdString()));
            if(a)
                clienti->pushBack(a);
        }
        else if(t.toStdString() == "Cliente Ristorante"){
            Restaurant_Client* a = 0;
            a = new Restaurant_Client(no.toStdString(),co.toStdString(),cod.toStdString(),Indirizzo(vi.toStdString(),nu.toStdString(),cit.toStdString(),pro.toStdString(),stat.toStdString()));
            if(a)
                clienti->pushBack(a);
        }
        //l'emissione del segnale finito() provoca il refresh della tabella dei clienti e fa in modo che la
        //mainwindow possa tener traccia dei cambiamenti al contenitore non ancora salvati su file
        emit finito();
    }
    else{
        intro->setStyleSheet("color: red");
        intro->setText("Non lasciare nessun\ncampo vuoto!");
    }

}
void aggiungiNuovoCliente::disableDate(int i){
    //se "Cliente Hotel" non è selezionato allora i due input per le date di check-in e check-out vengono disabilitati
    if(i == 1 || i == 2){
        indate->setDisabled(true);
        outdate->setDisabled(true);
    }
    else{
        indate->setDisabled(false);
        outdate->setDisabled(false);
    }
}
