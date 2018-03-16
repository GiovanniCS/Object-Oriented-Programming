#ifndef CARICA_H
#define CARICA_H
#include<string>
#include "clienti.h"
#include "utenti.h"

class QXmlStreamReader;
class Data;
class Spa_Client;
class Restaurant_Client;
using std::string;

class Carica
{
public:
    Carica();
    void utenti(Utenti*);
    bool utenti();
    void clienti(Clienti*);
    bool clienti();
private:
    string erroreClienti,erroreUtenti;
    void readIndirizzo(QXmlStreamReader&,string&, string&, string&, string&, string&);
    void readData(QXmlStreamReader&,Data&);
    void readDate(QXmlStreamReader&,Data&, Data&);
    void readServizio(QXmlStreamReader&,Data&, string&);
    void readServizi(QXmlStreamReader&,Spa_Client*);
    void readScontrino(QXmlStreamReader&,Data&, int&, double&);
    void readScontrini(QXmlStreamReader&,Restaurant_Client*);
    void leggi(QXmlStreamReader&, string&, string&);

};

#endif // CARICA_H
