#ifndef CARICA_UTENTI_H
#define CARICA_UTENTI_H

#include <QFile>
#include <QString>
#include <QDir>
#include <QXmlStreamReader>
#include "utenti.h"
using std::string;

//Questo header si occupa, dato un oggetto di tipo Utenti, di leggere un file xml contenente tutte le informazioni relative agli utenti
//e di inserirle nel suddetto oggetto.
//Inoltre se il documento non è ben formato o non è presente nella directory dell'eseguibile, assegna un messaggio di errore
//ad una stringa passata per riferiento.
void leggi(QXmlStreamReader& xmlreader, string& u, string& p){
    while(!(xmlreader.tokenType()==xmlreader.EndElement)){
        if(xmlreader.name()=="username"){
            u = xmlreader.readElementText().toStdString();
            xmlreader.readNext();
        }
        if(xmlreader.name()=="password"){
            p = xmlreader.readElementText().toStdString();
            xmlreader.readNext();
        }
        xmlreader.readNext();
    }
}
void inserisci(Utenti& u,std::string& errore){
    QString filename("./utenti.xml");
    QFile file(filename);
    QXmlStreamReader xmlreader;
    if(file.open(QFile::ReadOnly)){
        xmlreader.setDevice(&file);
        while(!xmlreader.atEnd() && !xmlreader.hasError()){
            QXmlStreamReader::TokenType token = xmlreader.readNext();
            if(token==QXmlStreamReader::StartDocument)  continue;
            if(xmlreader.isStartElement()){
                if(xmlreader.name()=="amministratore"){
                    string username, password;
                    leggi(xmlreader,username,password);
                    u.aggiungi("amministratore",username,password);
                    xmlreader.readNext();
                }
                if(xmlreader.name()=="base"){
                    string username, password;
                    leggi(xmlreader,username,password);
                    u.aggiungi("base",username,password);
                    xmlreader.readNext();
                }
                if(xmlreader.name()=="premium"){
                    string username, password;
                    leggi(xmlreader,username,password);
                    u.aggiungi("premium",username,password);
                    xmlreader.readNext();
                }
            }
        }
        file.close();
        errore="";
    }
    else errore="File degli utenti non trovato";
}

#endif // CARICA_UTENTI_H
