#ifndef TAB_WIDGET_AMMINISTRATORE_H
#define TAB_WIDGET_AMMINISTRATORE_H
#include <QTabWidget>

class Clienti;
class Utenti;
class tabellaUtenti;
class tabellaClienti;
class ricercaClienti;
//classe dedicata all'interazione con utenti amministratori
class TabWidgetAmministratore: public QTabWidget{
    Q_OBJECT
private:
    Clienti* clienti;
    Utenti* utenti;
    tabellaUtenti* widgetUtenti;
    tabellaClienti* widgetClienti;
    ricercaClienti* widgetRicerca;
public:
    TabWidgetAmministratore(Utenti* =0, Clienti* =0, QWidget* =0);
public slots:
    void aggiungiUtente();
    void aggiungiCliente();
signals:
    void daSalvare();
    void finito();
};
#endif // TAB_WIDGET_AMMINISTRATORE_H
