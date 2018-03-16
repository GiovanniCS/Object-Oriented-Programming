#include "salva.h"
#include <QFile>
#include <QString>
#include <QXmlStreamWriter>
#include "clienti.h"
#include "utenti.h"
#include<string>

//salvataggio di tutti i clienti in memoria in un file xml che sovrascrive quello di caricamento
void Salva::salvaIndirizzo(QXmlStreamWriter& xmlWriter, const Indirizzo& ind){
    QString via, numero, citta, prov, stato;
    via = QString::fromStdString(ind.getVia());
    numero = QString::fromStdString(ind.getNumeroCivico());
    citta = QString::fromStdString(ind.getCitta());
    prov = QString::fromStdString(ind.getProvincia());
    stato = QString::fromStdString(ind.getStato());
    xmlWriter.writeStartElement("indirizzo");
    xmlWriter.writeTextElement("via",via);
    xmlWriter.writeTextElement("numero",numero);
    xmlWriter.writeTextElement("citta",citta);
    xmlWriter.writeTextElement("stato",stato);
    xmlWriter.writeTextElement("prov",prov);
    xmlWriter.writeEndElement();
}

void Salva::salvaData(QXmlStreamWriter& xmlWriter, const Data& d){
    xmlWriter.writeStartElement("data");
    xmlWriter.writeAttribute("min",QString(QString::number(d.GetMin())));
    xmlWriter.writeAttribute("ora",QString(QString::number(d.GetOra())));
    xmlWriter.writeAttribute("giorno",QString(QString::number(d.GetGior())));
    xmlWriter.writeAttribute("mese",QString(QString::number(d.GetMese())));
    xmlWriter.writeAttribute("anno",QString(QString::number(d.GetAnno())));
    xmlWriter.writeEndElement();
}

void Salva::salvaDate(QXmlStreamWriter& xmlWriter, Hotel_Client* hc){
    Data in = hc->getIn(); Data out = hc->getOut();
    xmlWriter.writeStartElement("date");
    salvaData(xmlWriter,in);
    salvaData(xmlWriter,out);
    xmlWriter.writeEndElement();
}

void Salva::salvaServizi(QXmlStreamWriter& xmlWriter, const Spa_Client* sc){
    xmlWriter.writeStartElement("servizi");
    unsigned int dimensione = sc->numeroServizi();
    for(unsigned int i = 1; i <= dimensione; ++i){
        Data d; string tipo, opzionale ="";
        sc->leggiServizio(i,d,tipo,opzionale);
        xmlWriter.writeStartElement(QString::fromStdString(tipo));
        salvaData(xmlWriter,d);
        xmlWriter.writeTextElement("tipo",QString::fromStdString(opzionale));
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
}

void Salva::salvaScontrino(QXmlStreamWriter& xmlWriter, const Data& d, int i, double dd){
    xmlWriter.writeStartElement("scontrino");
    salvaData(xmlWriter,d);
    xmlWriter.writeTextElement("persone",QString::number(i));
    xmlWriter.writeTextElement("totale",QString::number(dd));
    xmlWriter.writeEndElement();
}

void Salva::salvaScontrini(QXmlStreamWriter& xmlWriter, const Restaurant_Client* rc){
    xmlWriter.writeStartElement("scontrini");
    unsigned int dimensione = rc->numeroScontrini();
    for(unsigned int i = 1; i <= dimensione; ++i){
        Data d; int g; double s;
        rc->leggiScontrino(i,d,g,s);
        salvaScontrino(xmlWriter,d,g,s);
    }
    xmlWriter.writeEndElement();
}


void Salva::clienti(Clienti* c){
    QXmlStreamWriter xmlWriter;
    QString filename("./clienti.xml");
    QFile file(filename);
    file.open(QFile::WriteOnly);
    xmlWriter.setDevice(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("clienti");
    Clienti::Iteratore it = c->begin();
    for(; it!= c->end() && !xmlWriter.hasError(); ++it){
        Abstract_Client* a = (*c)[it];
        QString nome = QString::fromStdString(a->getNome());
        QString cognome = QString::fromStdString(a->getCognome());
        QString codice = QString::fromStdString(a->getCodiceFiscale());
        const Indirizzo* ind = a->getPuntIndirizzo();
        if(dynamic_cast<Restaurant_Client*>(a) && !dynamic_cast<Hotel_Client*>(a)){
            Restaurant_Client* ra = dynamic_cast<Restaurant_Client*>(a);
            xmlWriter.writeStartElement("ristorante");
            xmlWriter.writeTextElement("nome",nome);
            xmlWriter.writeTextElement("cognome",cognome);
            xmlWriter.writeTextElement("codice_fisc",codice);
            salvaIndirizzo(xmlWriter,*ind);
            salvaScontrini(xmlWriter,ra);
            xmlWriter.writeEndElement();
        }
        else if(dynamic_cast<Spa_Client*>(a) && !dynamic_cast<Hotel_Client*>(a)){
            Spa_Client* sa = dynamic_cast<Spa_Client*>(a);
            xmlWriter.writeStartElement("spa");
            xmlWriter.writeTextElement("nome",nome);
            xmlWriter.writeTextElement("cognome",cognome);
            xmlWriter.writeTextElement("codice_fisc",codice);
            salvaIndirizzo(xmlWriter,*ind);
            salvaServizi(xmlWriter,sa);
            xmlWriter.writeEndElement();

        }
        else if(dynamic_cast<Hotel_Client*>(a)){
            Hotel_Client* ha = dynamic_cast<Hotel_Client*>(a);
            xmlWriter.writeStartElement("hotel");
            xmlWriter.writeTextElement("nome",nome);
            xmlWriter.writeTextElement("cognome",cognome);
            xmlWriter.writeTextElement("codice_fisc",codice);
            salvaIndirizzo(xmlWriter,*ind);
            //stampa delle date
            salvaDate(xmlWriter,ha);
            salvaServizi(xmlWriter,ha);
            salvaScontrini(xmlWriter,ha);
            xmlWriter.writeEndElement();

        }
    }
    xmlWriter.writeEndElement();
    file.close();
}

//salvataggio di tutti gli utenti in memoria in un file xml che sovrascrive quello di caricamento
void Salva::utenti(Utenti* u){
    QXmlStreamWriter xmlWriter;
    QString filename("./utenti.xml");
    QFile file(filename);
    file.open(QFile::WriteOnly);
    xmlWriter.setDevice(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("utenti");
    unsigned int dimensione = u->size();
    for(unsigned int i = 1; i<= dimensione; ++i){
        std::string nome, pass, tipo;
        u->leggiUtente(i,nome,pass,tipo);
        xmlWriter.writeStartElement(QString::fromStdString(tipo));
        xmlWriter.writeTextElement("username",QString::fromStdString(nome));
        xmlWriter.writeTextElement("password",QString::fromStdString(pass));
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    file.close();
}
