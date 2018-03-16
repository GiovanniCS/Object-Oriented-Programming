#ifndef RICERCA_CLIENTI_H
#define RICERCA_CLIENTI_H
#include <QWidget>
class Clienti;
class QComboBox;
class QSpinBox;
class QTableWidget;
class queryObject;
//tab disponibile per gli amministratori e gli utenti premium, permette di fare delle ricerche tra i clienti
//attraverso queryObject e di mostrarne i risultati nella tabella sottostante gli input.
class ricercaClienti: public QWidget{
    Q_OBJECT
private:
    Clienti* clienti;
    QComboBox* tipo;
    QSpinBox* spinspesa;
    QComboBox* dove;
    QTableWidget* tabella;
    queryObject* queryobject;
public:
    ricercaClienti(QWidget* =0,Clienti* =0);
public slots:
    void query();
};
#endif // RICERCA_CLIENTI_H
