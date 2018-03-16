#include "carica.h"
#include <QFile>
#include <QString>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>



Carica::Carica()
{
    erroreClienti = "";
    erroreUtenti = "";
}

void Carica::readIndirizzo(QXmlStreamReader& xmlreader,string& via, string& numero, string& citta, string& prov, string& stato){
    while(!(xmlreader.tokenType()==xmlreader.EndElement)){
        if(xmlreader.name()=="via"){
            via=xmlreader.readElementText().toStdString();
            xmlreader.readNext();
        }
        if(xmlreader.name()=="numero"){
            numero=xmlreader.readElementText().toStdString();
            xmlreader.readNext();
        }
        if(xmlreader.name()=="citta"){
            citta=xmlreader.readElementText().toStdString();
            xmlreader.readNext();
        }
        if(xmlreader.name()=="prov"){
            prov=xmlreader.readElementText().toStdString();
            xmlreader.readNext();
        }
        if(xmlreader.name()=="stato"){
            stato=xmlreader.readElementText().toStdString();
            xmlreader.readNext();
        }
        xmlreader.readNext();
    }
}
void Carica::readData(QXmlStreamReader& xmlreader,Data& d){
    foreach(const QXmlStreamAttribute &attr, xmlreader.attributes()) {
        if (attr.name().toString() == "min") {
            int min = attr.value().toInt();
            d.setMin(min);
        }
        else if(attr.name().toString() == "ora"){
            int ora = attr.value().toInt();
            d.setOra(ora);
        }
        else if(attr.name().toString() == "giorno"){
            int gio = attr.value().toInt();
            d.setGior(gio);
        }
        else if(attr.name().toString() == "mese"){
            int mese = attr.value().toInt();
            d.setMese(mese);
        }
        else if(attr.name().toString() == "anno"){
            int anno = attr.value().toInt();
            d.setAnno(anno);
        }
    }
    xmlreader.readNext();
}
void Carica::readDate(QXmlStreamReader& xmlreader,Data& in, Data& out){
    bool ok = true;
    while(!(xmlreader.tokenType()==xmlreader.EndElement)){
        if(xmlreader.name()=="data" &&ok){
            readData(xmlreader,in);
            ok = false;
        }
        else if(xmlreader.name()=="data" && !ok)
            readData(xmlreader,out);

        xmlreader.readNext();
    }
}
void Carica::readServizio(QXmlStreamReader& xmlreader,Data& d, string& stipo){
    while(!(xmlreader.tokenType()==xmlreader.EndElement)){
        if(xmlreader.name()=="data"){
            readData(xmlreader,d);
        }
        else if(xmlreader.name()=="tipo"){
            stipo=xmlreader.readElementText().toStdString();
            xmlreader.readNext();
        }
        xmlreader.readNext();
    }
}


void Carica::readServizi(QXmlStreamReader& xmlreader,Spa_Client* cliente){
    while(!(xmlreader.tokenType()==xmlreader.EndElement)){
        if(xmlreader.name()=="idromassaggio"){
            Data d; string stipo;
            readServizio(xmlreader,d,stipo);
            cliente->nuovo_Servizio(d,"idromassaggio");
            xmlreader.readNext();
        }
        if(xmlreader.name()=="bagnoturco"){
            Data d; string stipo;
            readServizio(xmlreader,d,stipo);
            cliente->nuovo_Servizio(d,"bagnoturco");
            xmlreader.readNext();
        }
        if(xmlreader.name()=="sauna"){
            Data d; string stipo;
            readServizio(xmlreader,d,stipo);
            cliente->nuovo_Servizio(d,"sauna");
            xmlreader.readNext();
        }
        if(xmlreader.name()=="massaggio"){
            Data d; string stipo;
            readServizio(xmlreader,d,stipo);
            cliente->nuovo_Servizio(d,"massaggio",stipo);
            xmlreader.readNext();
        }
        if(xmlreader.name()=="piscina"){
            Data d; string stipo;
            readServizio(xmlreader,d,stipo);
            cliente->nuovo_Servizio(d,"piscina");
            xmlreader.readNext();
        }
        if(xmlreader.name()=="palestra"){
            Data d; string stipo;
            readServizio(xmlreader,d,stipo);
            cliente->nuovo_Servizio(d,"palestra");
            xmlreader.readNext();
        }
        xmlreader.readNext();
    }
}

void Carica::readScontrino(QXmlStreamReader& xmlreader,Data& d, int& pers, double& tot){
    while(!(xmlreader.tokenType()==xmlreader.EndElement)){
        if(xmlreader.name()=="data"){
            readData(xmlreader,d);
        }
        else if(xmlreader.name()=="persone"){
            pers=xmlreader.readElementText().toInt();
            xmlreader.readNext();
        }
        else if(xmlreader.name()=="totale"){
            tot=xmlreader.readElementText().toDouble();
            xmlreader.readNext();
        }
        xmlreader.readNext();
    }
}

void Carica::readScontrini(QXmlStreamReader& xmlreader,Restaurant_Client* cliente){
    while(!(xmlreader.tokenType()==xmlreader.EndElement)){
        if(xmlreader.name()=="scontrino"){
            Data d; int p; double t;
            readScontrino(xmlreader,d,p,t);
            cliente->nuovo_Scontrino(d,p,t);
            xmlreader.readNext();
        }
        xmlreader.readNext();
    }
}

void Carica::clienti(Clienti* c){
    QString filename("./clienti.xml");
    QFile file(filename);
    QXmlStreamReader xmlreader;
    if(file.open(QFile::ReadOnly)){
        xmlreader.setDevice(&file);
        while(!xmlreader.atEnd() && !xmlreader.hasError()){
            QXmlStreamReader::TokenType token = xmlreader.readNext();
            if(token==QXmlStreamReader::StartDocument)  continue;
            if(xmlreader.isStartElement())
            {
                if(xmlreader.name()=="hotel")
                {
                    string nom, cogn, cod_fis;
                    string via, numero,citta,prov,stato;
                    Data in, out;
                    Hotel_Client* punt=0;
                    while(!(xmlreader.tokenType()==xmlreader.EndElement))
                    {
                        if(xmlreader.name()=="nome"){
                            nom=xmlreader.readElementText().toStdString();
                            xmlreader.readNext();
                        }
                        if(xmlreader.name()=="cognome"){
                             cogn=xmlreader.readElementText().toStdString();
                             xmlreader.readNext();
                         }
                        if(xmlreader.name()=="codice_fisc"){
                            cod_fis=xmlreader.readElementText().toStdString();
                            xmlreader.readNext();
                        }
                        if(xmlreader.name()=="indirizzo"){
                            readIndirizzo(xmlreader,via,numero,citta,prov,stato);
                            xmlreader.readNext();
                        }
                        if(xmlreader.name()=="date"){
                            readDate(xmlreader,in,out);
                            punt = new Hotel_Client(nom,cogn,cod_fis,Indirizzo(via,numero,citta,prov,stato),in,out);
                            xmlreader.readNext();
                        }
                        if(xmlreader.name()=="servizi"){
                            if(punt)
                                readServizi(xmlreader,punt);
                            xmlreader.readNext();
                        }
                        if(xmlreader.name()=="scontrini"){
                            if(punt)
                                readScontrini(xmlreader,punt);
                            xmlreader.readNext();
                        }
                        xmlreader.readNext();
                    }
                    c->pushBack(punt);
                }
                else if(xmlreader.name()=="spa"){
                    string nom, cogn, cod_fis;
                    string via, numero,citta,prov,stato;
                    Spa_Client* punt=0;
                    while(!(xmlreader.tokenType()==xmlreader.EndElement))
                    {
                        if(xmlreader.name()=="nome"){
                            nom=xmlreader.readElementText().toStdString();
                            xmlreader.readNext();
                        }
                        if(xmlreader.name()=="cognome"){
                             cogn=xmlreader.readElementText().toStdString();
                             xmlreader.readNext();
                         }
                        if(xmlreader.name()=="codice_fisc"){
                            cod_fis=xmlreader.readElementText().toStdString();
                            xmlreader.readNext();
                        }
                        if(xmlreader.name()=="indirizzo"){
                            readIndirizzo(xmlreader,via,numero,citta,prov,stato);
                            xmlreader.readNext();
                            punt = new Spa_Client(nom,cogn,cod_fis,Indirizzo(via,numero,citta,prov,stato));
                        }
                        if(xmlreader.name()=="servizi"){
                            if(punt)
                                readServizi(xmlreader,punt);
                            xmlreader.readNext();
                        }
                        xmlreader.readNext();
                    }
                    c->pushBack(punt);
                }
                else if(xmlreader.name()=="ristorante")
                {
                    string nom, cogn, cod_fis;
                    string via, numero,citta,prov,stato;
                    Restaurant_Client* punt=0;
                    while(!(xmlreader.tokenType()==xmlreader.EndElement))
                    {
                        if(xmlreader.name()=="nome"){
                            nom=xmlreader.readElementText().toStdString();
                            xmlreader.readNext();
                        }
                        if(xmlreader.name()=="cognome"){
                             cogn=xmlreader.readElementText().toStdString();
                             xmlreader.readNext();
                         }
                        if(xmlreader.name()=="codice_fisc"){
                            cod_fis=xmlreader.readElementText().toStdString();
                            xmlreader.readNext();
                        }
                        if(xmlreader.name()=="indirizzo"){
                            readIndirizzo(xmlreader,via,numero,citta,prov,stato);
                            xmlreader.readNext();
                            punt = new Restaurant_Client(nom,cogn,cod_fis,Indirizzo(via,numero,citta,prov,stato));
                        }
                        if(xmlreader.name()=="scontrini"){
                            if(punt)
                                readScontrini(xmlreader,punt);
                            xmlreader.readNext();
                        }
                        xmlreader.readNext();
                    }
                    c->pushBack(punt);
                }
                xmlreader.readNext();
            }
        }
        file.close();
        if(!xmlreader.hasError()) erroreClienti = "";
        else erroreClienti ="Errore durante la lettura del file clienti.xml";
    }
    else    erroreClienti = "File dei clienti non trovato";
}
void Carica::leggi(QXmlStreamReader& xmlreader, string& u, string& p){
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

void Carica::utenti(Utenti* u){
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
                    u->aggiungi("amministratore",username,password);
                    xmlreader.readNext();
                }
                if(xmlreader.name()=="base"){
                    string username, password;
                    leggi(xmlreader,username,password);
                    u->aggiungi("base",username,password);
                    xmlreader.readNext();
                }
                if(xmlreader.name()=="premium"){
                    string username, password;
                    leggi(xmlreader,username,password);
                    u->aggiungi("premium",username,password);
                    xmlreader.readNext();
                }
            }
        }
        file.close();
        erroreUtenti="";
    }
    else erroreUtenti="File degli utenti non trovato";
}



bool Carica::clienti(){
    return erroreClienti == "";
}
bool Carica::utenti(){
    return erroreUtenti == "";
}
