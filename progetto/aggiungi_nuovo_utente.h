#ifndef AGGIUNGI_NUOVO_UTENTE_H
#define AGGIUNGI_NUOVO_UTENTE_H

class Utenti;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
#include <QDialog>

//finestra di dialogo che permette di aggiungere un nuovo utente, "invocata" dalla funzione Modifica->Aggiungi Utente e disponibile solo per
//gli utenti amministratori
class aggiungiNuovoUtente:public QDialog{
    Q_OBJECT
private:
    Utenti* utenti;
    QLabel* intro;
    QComboBox* tipo;
    QLineEdit* userEdit;
    QLineEdit* passEdit;
    QPushButton* insert;
public:
    aggiungiNuovoUtente(QWidget* =0, Utenti* =0);
public slots:
    void verificaEinserisci();
signals:
    void finito();
};
#endif // AGGIUNGI_NUOVO_UTENTE_H
