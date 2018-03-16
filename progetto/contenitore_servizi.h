#ifndef CONTENITORE_SERVIZI_H
#define CONTENITORE_SERVIZI_H
#include "servizio_astratto.h"
#include <QString>
//contenitore dei servizi relativi ad uno specifico cliente della Spa o di Hotel
//Ogni nodo della lista è caratterizzato da un puntatore ad un servizio astratto ( base di derivazione per tutti i
//servizi concreti e da un puntatore al nodo successivo. Gestione della memoria in modo non condiviso.
//L'intera struttura dati è allocata sullo heap e la distruzione degli oggetti è profonda.
class Contenitore_Servizi{
private:
    class Servizio{
    public:
        Servizio_astratto* s;
        Servizio* next;
        Servizio(Servizio_astratto*, Servizio* = 0);
        ~Servizio();
    };
    static void elimina(Servizio*);
    Servizio* inizio;
public:
    Contenitore_Servizi();
    ~Contenitore_Servizi();
    double calcolaTotale() const;
    void aggiungi(Servizio_astratto*);
    QString stampaServizi() const;
    unsigned int size() const;
    void leggiServizio(unsigned int, Data&,std::string&,std::string&) const;
};

#endif
