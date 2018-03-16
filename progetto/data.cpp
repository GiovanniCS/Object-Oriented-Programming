#include "data.h"

Data::Data(int mi, int o, int g, int m, int a){
    minuto = (mi>=0&&mi<60) ? mi : 0;
    ora = (o>=0&&o<24) ? o : 0;
    giorno = (g>0&&g<32) ? g : 1;
    mese = (m>0&&m<13) ? m : 1;
    anno = (a>1900&&a<=3000) ? a : 2017;
}

void Data::setMin(int mi) {minuto=mi;}

void Data::setOra(int o) {ora=o;}

void Data::setGior(int g) {giorno=g;}

void Data::setMese(int me) {mese=me;}

void Data::setAnno(int an) {anno=an;}

int Data::GetMin() const { return minuto; }

int Data::GetOra() const { return ora; }

int Data::GetGior() const { return giorno; }

int Data::GetMese() const { return mese; }

int Data::GetAnno() const { return anno; }

bool Data::operator <=(const Data& d)const{
    return anno<d.anno || (anno==d.anno && mese<d.mese) ||
        (anno==d.anno && mese==d.mese && giorno<d.giorno) ||
        (anno==d.anno && mese==d.mese && giorno==d.giorno && ora<d.ora) ||
        (anno==d.anno && mese==d.mese && giorno==d.giorno && ora==d.ora && minuto<d.minuto) ||
        (anno==d.anno && mese==d.mese && giorno==d.giorno && ora==d.ora && minuto==d.minuto);
}

Data& Data::operator++(){
    ++giorno;
    if(giorno >31 || (giorno == 31 && ( mese == 4 || mese == 6 || mese == 9 || mese == 11 )) || (giorno==29 && mese == 2)){
        ++mese;
        giorno = 1;
        if(mese > 12){
            anno++;
            mese = 1;
        }
    }
    return *this;
}
//printData riceve una stringa per riferimento e ci aggiunge la data formattata
void Data::printData(QString& s) const{
    s = s + QString::fromStdString("Ora ");
    if(GetOra()<10)	s = s +"0";
    s = s + QString::number(GetOra()) + QString::fromStdString(":");
    if(GetMin()<10)	s = s +QString::fromStdString("0");
    s = s + QString::number(GetMin()) ; s = s +QString::fromStdString("  ");

    if(GetGior()<10)	s = s +QString::fromStdString("0");
    s = s + QString::number(GetGior()) + QString::fromStdString("/");

    if(GetMese()<10)	s = s +QString::fromStdString("0");
    s = s + QString::number(GetMese()) + QString::fromStdString("/");

    s = s + QString::number(GetAnno());
}
