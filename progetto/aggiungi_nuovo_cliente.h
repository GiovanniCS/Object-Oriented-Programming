#ifndef AGGIUNGI_NUOVO_CLIENTE_H
#define AGGIUNGI_NUOVO_CLIENTE_H
#include <QDialog>
class Clienti;
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QDateTimeEdit;
//finestra di dialogo che permette di aggiungere un nuovo cliente, "invocata" dalla funzione Modifica->Aggiungi Cliente e disponibile solo per
//gli utenti amministratori
class aggiungiNuovoCliente:public QDialog{
    Q_OBJECT
private:
    Clienti* clienti;
    QComboBox* tipo;
    QLabel* intro;
    QLineEdit* nomeEdit;
    QLineEdit* cognomeEdit;
    QLineEdit* codiceEdit;
    QLineEdit* viaEdit;
    QLineEdit* numeroEdit;
    QLineEdit* cittaEdit;
    QLineEdit* provinciaEdit;
    QLineEdit* statoEdit;
    QPushButton* insert;
    QDateTimeEdit* indate;
    QDateTimeEdit* outdate;
public:
    aggiungiNuovoCliente(QWidget* =0, Clienti* =0);
signals:
    void finito();
public slots:
    void disableDate(int);
    void verificaEinserisci();
};
#endif // AGGIUNGI_NUOVO_CLIENTE_H
