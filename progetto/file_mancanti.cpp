#include "file_mancanti.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
//se durante il caricamento da file qualcosa non va come previsto, al primo tentativo di autenticazione
//questa finestra di dialogo da alcune info all' utente
FileMancanti::FileMancanti(QWidget* parent):QDialog(parent){
    setWindowTitle("File Mancanti");
    setModal(true);
    setFixedSize(390,390);
    QVBoxLayout* verticale = new QVBoxLayout();
    QLabel* err1 = new QLabel("Mi serve aiuto :(",this);
    err1->setAlignment(Qt::AlignCenter);
    QLabel* err2 = new QLabel("Sembra che alcuni file necessari al buon \nfunzionamento del programma non siano presenti\no non siano validi.\n",this);
    err2->setAlignment(Qt::AlignCenter);
    QLabel* err3 = new QLabel("Controlla che nella directory del mio eseguibile\nsiano presenti \"clienti.xml\" e \"utenti.xml\" \n anche con il solo elemento radice definito!\n",this);
    err3->setAlignment(Qt::AlignCenter);
    QLabel* es1 = new QLabel("Esempio clienti.xml:\n<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<clienti></clienti>",this);
    es1->setAlignment(Qt::AlignCenter);
    QLabel* es2 = new QLabel("Esempio utenti.xml:\n<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<utenti></utenti>\n",this);
    es2->setAlignment(Qt::AlignCenter);
    verticale->addWidget(err1);
    verticale->addWidget(err2);
    verticale->addWidget(err3);
    verticale->addWidget(es1);
    verticale->addWidget(es2);
    QPushButton* riprova = new QPushButton("Riprova!",this);
    verticale->addWidget(riprova);
    setLayout(verticale);
    connect(riprova,SIGNAL(clicked()),this,SLOT(close()));
}
