#ifndef ERRORE_DIALOG_H
#define ERRORE_DIALOG_H
#include <QDialog>
//Finestra di dialogo che avverte l'utente dell'assenza delle credenziali d'accesso appena inserite
class ErroreDialog: public QDialog{
public:
    ErroreDialog(QWidget* = 0);
};
#endif // ERRORE_DIALOG_H
