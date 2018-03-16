#ifndef UTENTE_H
#define UTENTE_H
#include <string>

using std::string;
//utente del programma caratterizzato da username, password e un tipo (base|premium|amministratore).
class Utente{
private:
    string username, password, tipo;
public:
    Utente(string,string,string);
    void setUsername(string);
    void setPassword(string);
    void setTipo(string);
    string getUsername() const;
    string getPassword() const;
    string getTipo() const;
};

#endif // UTENTE_H
