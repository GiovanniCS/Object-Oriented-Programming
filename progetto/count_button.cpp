#include "count_button.h"
countButton::countButton(QString nome,QWidget* parent, int numero):QPushButton(nome,parent),i(numero){
    connect(this,SIGNAL(clicked()),this,SLOT(emetti()));
}
//Quando premuto, il countButton emette un segnale dove il parametro è l'intero di costruzione
void countButton::emetti(){
    emit cliccato(i);
}
