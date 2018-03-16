#ifndef TAB_WIDGET_PREMIUM_H
#define TAB_WIDGET_PREMIUM_H
#include <QTabWidget>

class Clienti;
class ricercaClienti;
//classe dedicata all'interazione con utenti premium
class TabWidgetPremium: public QTabWidget{
    Q_OBJECT
private:
    Clienti* clienti;
    ricercaClienti* widgetRicerca;
public:
    TabWidgetPremium(Clienti* =0,QWidget* =0);
};
#endif // TAB_WIDGET_PREMIUM_H
