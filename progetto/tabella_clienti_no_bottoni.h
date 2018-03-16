#ifndef TABELLA_CLIENTI_NO_BOTTONI_H
#define TABELLA_CLIENTI_NO_BOTTONI_H
#include <QTableWidget>

class Clienti;
//classe dedicata alla visualizzazione dei clienti (solo in tabWidgetPremium)
//senza possibilità di rimozione e lettura dei clienti nei dettagli.
class tabellaClientiNoButtottoni: public QTableWidget{
    Q_OBJECT
private:
    Clienti* clienti;
public:
    tabellaClientiNoButtottoni(QWidget* =0, Clienti* =0);
};
#endif // TABELLA_CLIENTI_NO_BOTTONI_H
