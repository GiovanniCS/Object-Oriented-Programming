#include "servizio_astratto.h"
Servizio_astratto::~Servizio_astratto(){}
Servizio_astratto::Servizio_astratto(const Data& d): data(d){}
Data Servizio_astratto::getData() const { return data; }
