#ifndef SALVA_H
#define SALVA_H

class QXmlStreamWriter;
class Indirizzo;
class Data;
class Hotel_Client;
class Spa_Client;
class Restaurant_Client;
class Clienti;
class Utenti;

class Salva
{
public:
    void clienti(Clienti*);
    void utenti(Utenti*);
private:
    void salvaIndirizzo(QXmlStreamWriter&, const Indirizzo&);
    void salvaData(QXmlStreamWriter&, const Data&);
    void salvaDate(QXmlStreamWriter&, Hotel_Client*);
    void salvaServizi(QXmlStreamWriter&, const Spa_Client*);
    void salvaScontrino(QXmlStreamWriter&, const Data&, int, double);
    void salvaScontrini(QXmlStreamWriter&, const Restaurant_Client*);

};

#endif // SALVA_H
