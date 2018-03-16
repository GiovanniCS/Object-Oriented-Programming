#ifndef AGGIUNGI_SERVIZIO_H
#define AGGIUNGI_SERVIZIO_H
#include <QDialog>

class QComboBox;
class QLabel;
class QLineEdit;
class QDateTimeEdit;
class Abstract_Client;

//finestra di dialogo che permette di aggiungere un nuovo servizio al cliente rappresentato dall'oggetto puntato da cliente, "invocata"
//dal pulsante "Aggiungi servizio" in dettagliCliente (se il cliente è un cliente della Spa o di hotel.
//Disponibile solo per gli utenti amministratori.
class aggiungiServizio: public QDialog{
    Q_OBJECT
private:
    Abstract_Client* cliente;
    QDateTimeEdit* data;
    QComboBox* tipo;
    QLabel* lab;
    QLineEdit* edit;
public:
    aggiungiServizio(QWidget* =0, Abstract_Client* =0);
public slots:
    void disableEdit(int);
    void inserisci();
signals:
    void daSalvare();
};
#endif // AGGIUNGI_SERVIZIO_H
