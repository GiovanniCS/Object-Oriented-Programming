#include "ultimo_amministratore.h"
#include <QLabel>
#include <QVBoxLayout>

ultimoAmministratore::ultimoAmministratore(QWidget* parent): QDialog(parent){
    setWindowTitle("Attenzione");
    setModal(true);
    setFixedSize(360,100);
    QVBoxLayout* verticale = new QVBoxLayout();

    QLabel* lab = new QLabel("E' rimasto un unico amministratore nel sistema!\n Non è possibile rimuoverlo",this);
    lab->setAlignment(Qt::AlignCenter);
    verticale->addWidget(lab);
    setLayout(verticale);
}
