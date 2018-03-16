#ifndef DETTAGLI_CLIENTE_H
#define DETTAGLI_CLIENTE_H
#include <QDialog>

class QLineEdit;
class QLabel;
class Abstract_Client;
//finestra di dialogo che permette di visualizzare i dettagli di ogni cliente, modificarne i valori e aggiungere nuovi scontrini e/o servizi
//in base alla tipologia del cliente visualizzato.
//Disponibile solo per gli utenti amministratori.
class dettagliCliente: public QDialog{
    Q_OBJECT
private:
    Abstract_Client* cliente;
public:
    dettagliCliente(QWidget* =0, Abstract_Client* =0);
    QLineEdit* nomeedit,* cognomeedit, *codiceedit, *numeroedit, *viaedit, *cittaedit, *provinciaedit, *statoedit ;
    QLabel* errore;
public slots:
    void aggiornaCliente();
    void aggiungiScontr();
    void aggiungiServ();
signals:
    void daSalvare();
    void refresh();
};
#endif // DETTAGLI_CLIENTE_H
