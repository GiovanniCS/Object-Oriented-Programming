#ifndef TABELLA_UTENTI_H
#define TABELLA_UTENTI_H
#include <QTableWidget>

class Utenti;
//classe dedicata alla visualizzazione degli utenti (solo in tabWidgetAmministratore)
//con possibilità di rimozione e modifica di quest'ultimi.
class tabellaUtenti: public QTableWidget{
    Q_OBJECT
private:
    Utenti* utenti;
public:
    tabellaUtenti(QWidget* =0,Utenti* =0);
public slots:
    void elimina(int);
    void riDisegna();
    void aggiorna(int);
signals:
    void daSalvare();
};
#endif // TABELLA_UTENTI_H
