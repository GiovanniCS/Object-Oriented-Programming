#ifndef DATA_H
#define DATA_H
#include <QString>
//Data incapsula una semplice data, durante la costruzione si preoccupa di verificare che la data possa essere corretta
//e assegna valori "legali" quando necessario
class Data{
private:
        int minuto, ora, giorno, mese, anno;
public:
        Data(int = 0,int = 0,int = 0,int = 0,int = 2017);
        void setMin(int);
        void setOra(int);
        void setGior(int);
        void setMese(int);
        void setAnno(int);

        int GetMin() const;
        int GetOra() const;
        int GetGior() const;
        int GetMese() const;
        int GetAnno() const;
        bool operator <=(const Data&)const;
        Data& operator++();
        void printData(QString&) const;
};

#endif // DATA_H
