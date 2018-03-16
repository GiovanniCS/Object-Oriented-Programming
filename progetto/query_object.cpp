#include "query_object.h"
#include "clienti.h"

bool queryObject::locazione(Abstract_Client* a, std::string d){
    // Veneto   Italia   Europa
    // locazione dermina se il cliente appartiene ad una specifica area geografica o meno
    if(d == "Italia"){
        return (a->getPuntIndirizzo()->getStato() == "Italia" || a->getPuntIndirizzo()->getStato() == "italia");
    }
    if(d == "Veneto"){
        std::string prov = a->getPuntIndirizzo()->getProvincia();
        //bl pd ro tv ve vr vi
        return (prov == "BL" || prov == "bl" || prov == "PD" || prov == "pd"  ||
                prov =="RO" || prov =="ro" || prov =="TV" || prov =="tv" || prov =="VE" ||
                prov =="ve" || prov =="VR" || prov =="vr" || prov =="VI" || prov =="vi" ||
                prov == "vicenza" || prov == "Vicenza" || prov == "Padova" || prov == "padova" || prov == "Rovigo" ||
                prov == "rovigo" || prov == "treviso" || prov == "Treviso" || prov == "Venezia" || prov == "venezia"||
                prov == "verona" || prov == "Verona" || prov == "belluno" || prov == "Belluno");
    }
    else//if d == "Tutto il mondo"
        return true;
}

void queryObject::query(std::vector<Abstract_Client *> & v, Clienti* clienti, std::string chi, int quanto, std::string dove){
    Clienti::Iteratore it = clienti->begin();

    if(chi == "Cliente di Ristorante"){
        for(; it != clienti->end(); ++it){
            if(dynamic_cast<Restaurant_Client*>((*clienti)[it]) && !dynamic_cast<Hotel_Client*>((*clienti)[it]) &&
                    (*clienti)[it]->costo_totale() >= quanto){
                if(locazione((*clienti)[it],dove))
                    v.push_back((*clienti)[it]);
            }
        }
    }
    else if (chi == "Cliente di Spa"){
        for(; it != clienti->end(); ++it){
            if(dynamic_cast<Spa_Client*>((*clienti)[it]) && !dynamic_cast<Hotel_Client*>((*clienti)[it]) &&
                    (*clienti)[it]->costo_totale() >= quanto){
                if(locazione((*clienti)[it],dove))
                    v.push_back((*clienti)[it]);
            }
        }
    }
    else if (chi == "Cliente di Hotel"){
        for(; it != clienti->end(); ++it){
            if(dynamic_cast<Hotel_Client*>((*clienti)[it]) && (*clienti)[it]->costo_totale() >= quanto){
                if(locazione((*clienti)[it],dove))
                    v.push_back((*clienti)[it]);
            }
        }
    }
    else if(chi == "Clienti"){
        for(; it != clienti->end(); ++it){
            if((*clienti)[it]->costo_totale() >= quanto && locazione((*clienti)[it],dove))
                v.push_back((*clienti)[it]);
        }
    }
}
