#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <QtDebug>
#include <QtSql>

using namespace std;
// Klasi sem geymir upplýsingar um hverja einustu tölvu, þ.e. nafn, týpu, hvort hún var búin til eða ekki, ártal og fleira merkilegt.
class Computer
{
    private:
        int ID;
        string name;
        string type;
        bool wasBuilt;
        int buildYear;
        string info;

        void readData(QSqlQuery query);

    public:
        Computer();
        Computer(string name, string type, bool wasBuilt, int buildYear, string info);
        Computer(QSqlQuery q);

        string getName();
        int getBuildYear();
        string getType();
        bool getWasBuilt();
        string getInfo();
        int getId();
        void setId(int id);

        bool operator < (const Computer& r);

        friend ostream& operator << (ostream& out, const Computer& C);

};

#endif // COMPUTER_H
