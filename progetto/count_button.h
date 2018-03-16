#ifndef COUNT_BUTTON_H
#define COUNT_BUTTON_H
#include <QString>
#include <QPushButton>
//Pulsante caratterizzato dall'emisione di un segnale con parametro intero che rappresente il suo "ID"
//e può essere quindi associato a un particolare cliente.
class countButton: public QPushButton{
    Q_OBJECT
private:
    int i;
public:
    countButton(QString, QWidget* =0,int =0);
signals:
    void cliccato(int);
private slots:
    void emetti();
};
#endif // COUNT_BUTTON_H
