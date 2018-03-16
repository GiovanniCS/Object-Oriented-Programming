#ifndef AGGIUNGI_SCONTRINO_H
#define AGGIUNGI_SCONTRINO_H
#include <QDialog>

class Abstract_Client;
class QSpinBox;
class QLabel;
class QLineEdit;
class QDateTimeEdit;
class QDoubleSpinBox;
//finestra di dialogo che permette di aggiungere un nuovo scontrino al cliente rappresentato dall'oggetto puntato da cliente, "invocata"
//dal pulsante "Aggiungi scontrino" in dettagliCliente (se il cliente è un cliente di ristorante o di hotel.
//Disponibile solo per gli utenti amministratori.
class aggiungiScontrino: public QDialog{
    Q_OBJECT
private:
    Abstract_Client* cliente;
    QDateTimeEdit* data;
    QSpinBox* persone;
    QDoubleSpinBox* tot;
public:
    aggiungiScontrino(QWidget* =0, Abstract_Client* =0);
public slots:
    void inserisci();
signals:
    void daSalvare();
};

#endif // AGGIUNGI_SCONTRINO_H
