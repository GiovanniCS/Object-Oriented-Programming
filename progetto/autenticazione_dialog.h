#ifndef AUTENTICAZIONE_DIALOG_H
#define AUTENTICAZIONE_DIALOG_H
class Utenti;
class QPushButton;
class QLineEdit;
#include <QDialog>

//finestra di dialogo che permette di autenticarsi secondo tre tipologie di utenti, "invocata" dalla funzione Help->Seleziona Utente.
//AutenticazioneDialog delega all'oggetto di tipo Utenti la verifica delle credenziali e in caso di successo emette un segnale
//specifico per ogni tipo di utente che sarà poi raccolto per disegnare l'interfaccia corretta.
class AutenticazioneDialog: public QDialog
{
    Q_OBJECT
private:
    QLineEdit* passEdit;
    QLineEdit* userEdit;
    QPushButton* admin;
    QPushButton* baseu;
    QPushButton* premiumu;
    Utenti* u;
public:
    AutenticazioneDialog(QWidget *, Utenti*);
signals:
    void baseOk();
    void premiumOk();
    void amministratoreOk();
public slots:
    void validaAdmin();
    void validaPremium();
    void validaBase();
};

#endif // AUTENTICAZIONE_DIALOG_H
