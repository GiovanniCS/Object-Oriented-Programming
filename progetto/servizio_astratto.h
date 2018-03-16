#ifndef SERVIZIO_ASTRATTO_H
#define SERVIZIO_ASTRATTO_H
#include "data.h"
//base di derivazione per tutti i servizi offerti dall'hotel
//distruttore virtuale
class Servizio_astratto{
private:
    Data data;
public:
    virtual ~Servizio_astratto();
    Servizio_astratto(const Data& );
    virtual std::string getNome() const=0;
    virtual void getNomeS(std::string&, std::string&) const=0;
    virtual double getCosto() const=0;
    Data getData() const;
};
#endif // SERVIZIO_ASTRATTO_H
