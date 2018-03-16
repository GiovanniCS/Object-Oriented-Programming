#include "autenticazione_dialog.h"
#include "utenti.h"
#include "errore_dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

AutenticazioneDialog::AutenticazioneDialog(QWidget* parent = 0, Utenti* utenti =0): QDialog(parent), u(utenti)
{
    setWindowTitle("Login");
    setModal(true);
    setFixedSize(230,280);
    QVBoxLayout* verticale = new QVBoxLayout();

    QHBoxLayout* passwordlay = new QHBoxLayout();
    QLabel* passLabel = new QLabel("Password");
    passEdit = new QLineEdit;
    passEdit->setEchoMode(QLineEdit::Password);
    passwordlay->addWidget(passLabel);
    passwordlay->addWidget(passEdit);

    QHBoxLayout* userlay = new QHBoxLayout();
    QLabel* userLabel = new QLabel("Username");
    userEdit = new QLineEdit;
    userlay->addWidget(userLabel);
    userlay->addWidget(userEdit);

    QLabel * label = new QLabel("Effettua l'accesso come:");
    label->setAlignment(Qt::AlignCenter);

    admin = new QPushButton("Amministratore");
    baseu = new QPushButton("Utente Base");
    premiumu = new QPushButton("Utente Premium");
    connect(admin,SIGNAL(clicked()),this,SLOT(validaAdmin()));
    connect(this,SIGNAL(amministratoreOk()),this,SLOT(close()));

    connect(baseu,SIGNAL(clicked()),this,SLOT(validaBase()));
    connect(this,SIGNAL(premiumOk()),this,SLOT(close()));


    connect(premiumu,SIGNAL(clicked()),this,SLOT(validaPremium()));
    connect(this,SIGNAL(baseOk()),this,SLOT(close()));

    verticale->setSpacing(6);
    verticale->setMargin(11);

    verticale->addLayout(userlay);
    verticale->addLayout(passwordlay);
    verticale->addWidget(label);
    verticale->addWidget(admin);
    verticale->addWidget(premiumu);
    verticale->addWidget(baseu);
    this->setLayout(verticale);
}
//i tre metodi di validazione dell'utente raccolgono i dati inseriti e delegano il controllo della sua esistenza
//all'oggetto di tipo Utenti. Se non esite l'utente allora viene mostrata una finesta di dialogo d'errore, altrimenti
//viene emesso un segnale raccolto dalla mainindow che si occupa di disegnare l'interfaccia adeguata
void AutenticazioneDialog::validaAdmin(){
    QString user(userEdit->text());
    QString password(passEdit->text());
    if(u->esiteUtente("amministratore",user.toStdString(),password.toStdString()))
        emit amministratoreOk();
    else
    {
        ErroreDialog* e = new ErroreDialog(this);
        e->show();
    }
}
void AutenticazioneDialog::validaPremium(){
    QString user(userEdit->text());
    QString password(passEdit->text());
    if(u->esiteUtente("premium",user.toStdString(),password.toStdString()))
        emit premiumOk();
    else
    {
        ErroreDialog* e = new ErroreDialog(this);
        e->show();
    }
}
void AutenticazioneDialog::validaBase(){
    QString user(userEdit->text());
    QString password(passEdit->text());
    if(u->esiteUtente("base",user.toStdString(),password.toStdString()))
        emit baseOk();
    else
    {
        ErroreDialog* e = new ErroreDialog(this);
        e->show();
    }
}
