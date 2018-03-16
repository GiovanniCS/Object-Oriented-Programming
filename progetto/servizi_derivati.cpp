#include "servizi_derivati.h"
Idromassaggio::Idromassaggio(const Data& d): Servizio_astratto(d){}
double Idromassaggio::getCosto() const { return costo; }
double Idromassaggio::costo = 15.5;
std::string Idromassaggio::getNome() const { return "Idromassaggio"; }
void Idromassaggio::getNomeS(std::string& nome, std::string& opzionale) const{
    nome = "idromassaggio";
    opzionale = "";
}


Bagno_Turco::Bagno_Turco(const Data& d): Servizio_astratto(d){}
double Bagno_Turco::getCosto() const { return costo; }
double Bagno_Turco::costo = 21.3;
std::string Bagno_Turco::getNome() const { return "Bagno Turco"; }
void Bagno_Turco::getNomeS(std::string& nome, std::string& opzionale) const{
    nome = "bagnoturco";
    opzionale = "";
}


Sauna::Sauna(const Data& d): Servizio_astratto(d){}
double Sauna::getCosto() const { return costo; }
double Sauna::costo = 17.0;
std::string Sauna::getNome() const { return "Sauna"; }
void Sauna::getNomeS(std::string& nome, std::string& opzionale) const{
    nome = "sauna";
    opzionale = "";
}


Massaggio::Massaggio(const Data& d, const std::string& t): Servizio_astratto(d), tipo(t){}
double Massaggio::getCosto() const {
    return costoBase + ((tipo=="Tailandese"||tipo=="Shiatsu") ? 10.0 : 0);
}
double Massaggio::costoBase = 34.7;
std::string Massaggio::getNome() const { return (tipo=="" ? "Massaggio" : ("Massaggio " + tipo)); }
void Massaggio::getNomeS(std::string& nome, std::string& opzionale) const{
    nome = "massaggio"; opzionale = tipo;
}


Piscina::Piscina(const Data& d): Servizio_astratto(d){}
double Piscina::getCosto() const { return costo; }
double Piscina::costo = 10.0;
std::string Piscina::getNome() const { return "Piscina"; }
void Piscina::getNomeS(std::string& nome, std::string& opzionale) const{
    nome = "Piscina";
    opzionale = "";
}


Palestra::Palestra(const Data& d): Servizio_astratto(d){}
double Palestra::getCosto() const { return costo; }
double Palestra::costo = 16.5;
std::string Palestra::getNome() const { return "Palestra"; }
void Palestra::getNomeS(std::string& nome, std::string& opzionale) const{
    nome = "palestra";
    opzionale = "";
}
