#ifndef TABELLA_CLIENTI_H
#define TABELLA_CLIENTI_H
#include <QTableWidget>

class Clienti;
//classe dedicata alla visualizzazione dei clienti (solo in tabWidgetAmministratore)
//con possibilità di rimozione e lettura dei clienti nei dettagli tramite la classe dettagliCliente
class tabellaClienti: public QTableWidget{
    Q_OBJECT
private:
    Clienti* clienti;
public:
    tabellaClienti(QWidget* =0, Clienti* =0);
public slots:
    void elimina(int);
    void riDisegna();
    void apri(int);
signals:
    void daSalvare();
};
#endif // TABELLA_CLIENTI_H
