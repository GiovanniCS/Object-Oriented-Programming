#ifndef FILE_MANCANTI_H
#define FILE_MANCANTI_H

#include <QDialog>
//Se durante la lettura dei documenti xml accade qualcosa di imprevisto ( vedi ad es. carica_clienti.h ),
//quando l'utente tenta di autenticarsi, viene mostrata questa finestra di dialogo con alcune info
class FileMancanti: public QDialog{
public:
    FileMancanti(QWidget* =0);

};

#endif // FILE_MANCANTI_H
