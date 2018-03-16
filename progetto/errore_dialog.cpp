#include "errore_dialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
//finestra di dialogo che informa l'utente di non esser stato riconosciuto dal programma
ErroreDialog::ErroreDialog(QWidget* parent): QDialog(parent){
    setWindowTitle("Errore");
    setModal(true);
    setFixedSize(210,150);
    QVBoxLayout* verticale = new QVBoxLayout();
    QLabel* errLabel = new QLabel("Utente non riconosciuto :(",this);
    errLabel->setAlignment(Qt::AlignCenter);
    verticale->addWidget(errLabel);
    QPushButton* riprova = new QPushButton("Riprova!",this);
    verticale->addWidget(riprova);
    setLayout(verticale);
    connect(riprova,SIGNAL(clicked()),this,SLOT(close()));
}
