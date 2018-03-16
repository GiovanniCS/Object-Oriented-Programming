#ifndef ULTIMO_AMMINISTRATORE_H
#define ULTIMO_AMMINISTRATORE_H
#include <QDialog>
//Finestra di dialogo che avverte l'amministratore che sta tentando di eliminare l'ultimo amm. rimasto
//(funzionalità non prevista)
class ultimoAmministratore: public QDialog{
public:
    ultimoAmministratore(QWidget* =0);
};

#endif // ULTIMO_AMMINISTRATORE_H
