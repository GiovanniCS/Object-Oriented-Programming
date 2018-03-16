#ifndef TAB_WIDGET_BASE_H
#define TAB_WIDGET_BASE_H
#include <QTabWidget>

class Clienti;
//classe dedicata all'interazione con utenti base
class TabWidgetBase: public QTabWidget{
    Q_OBJECT
private:
    Clienti* clienti;
public:
    TabWidgetBase(Clienti* =0,QWidget* =0);

};
#endif // TAB_WIDGET_BASE_H
