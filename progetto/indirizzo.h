#ifndef INDIRIZZO_H
#define INDIRIZZO_H
#include <string>
using std::string;
//Indirizzo rappresenta un semplice indirizzo
class Indirizzo{
    private:
        string via, n_civico, citta, provincia, stato ;
    public:
        Indirizzo(const string& ,const string& ,const string& ,const string&, const string& );
        string getStato() const;
        void setStato(const string&);
        string getProvincia() const;
        void setProvincia(const string&);
        string getCitta() const;
        void setCitta(const string&);
        string getVia() const;
        void setVia(const string&);
        string getNumeroCivico() const;
        void setNumeroCivico(const string&);
    };

#endif // INDIRIZZO_H
