#ifndef SERVIZI_DERIVATI_H
#define SERVIZI_DERIVATI_H
#include "servizio_astratto.h"
#include <string>
//tutti i servizi offerti dall'hotel sono implementati come classi derivate da un servizio astratto
//Ogni servizio derivato implementa il metodo virtuale getCosto(), getNome() e getNomeS()
class Idromassaggio: public Servizio_astratto{
private:
    static double costo;
public:
    Idromassaggio(const Data& );
    double getCosto() const;
    std::string getNome() const;
    void getNomeS(std::string&, std::string&) const;
};

class Bagno_Turco: public Servizio_astratto{
private:
    static double costo;
public:
    Bagno_Turco(const Data& );
    double getCosto() const;
    std::string getNome() const;
    void getNomeS(std::string&, std::string&) const;
};

class Sauna: public Servizio_astratto{
private:
    static double costo;
public:
    Sauna(const Data& );
    double getCosto() const;
    std::string getNome() const;
    void getNomeS(std::string&, std::string&) const;
};

class Massaggio: public Servizio_astratto{
private:
    static double costoBase;
    std::string tipo;
public:
    Massaggio(const Data& , const std::string& ="");
    double getCosto() const;
    std::string getNome() const;
    void getNomeS(std::string&, std::string&) const;
};

class Piscina: public Servizio_astratto{
private:
    static double costo;
public:
    Piscina(const Data& );
    double getCosto() const;
    std::string getNome() const;
    void getNomeS(std::string&, std::string&) const;
};

class Palestra: public Servizio_astratto{
private:
    static double costo;
public:
    Palestra(const Data& );
    double getCosto() const;
    std::string getNome() const;
    void getNomeS(std::string&, std::string&) const;
};

#endif // SERVIZI_DERIVATI_H
