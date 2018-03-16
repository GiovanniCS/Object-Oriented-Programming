#ifndef QUERY_OBJECT_H
#define QUERY_OBJECT_H
#include <vector>
#include <string>

class Clienti;
class Abstract_Client;
//queryObject mette a disposizione un metodo, query,( ma è possibile implementarne praticamente infiniti)
//che inserisce nel vector passato per riferimento una selezione di puntatori a clienti che rispettano specifici
//vincoli. E' usato ad esempio nel tab di ricerca per gli amministratori e gli utenti premium
class queryObject{
private:
    bool locazione(Abstract_Client*,std::string);
public:
    void query(std::vector<Abstract_Client*>&, Clienti*, std::string, int, std::string);
};

#endif // QUERY_OBJECT_H
