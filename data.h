#ifndef DATA_H
#define DATA_H

#include "person.h"
#include "computer.h"
#include <vector>
#include <fstream>
#include <QtDebug>
#include <QtSql>

class Database
{

// Klasi fyrir gagnalagið.  Skrifar út í skrá frá vektor og úr skrá í vektor.
// Vektorinn síðan tekinn og sendur inn í domain-lagið.

private:
    QSqlDatabase db;
public:
    Database();
    ~Database();
    unsigned int addNewScientist(Person P);
    unsigned int addNewComputer(Computer C);
    void addNewLink(pair<Person, Computer> link);

    vector<Person> readScientistFromDb();
    vector<Computer> readComputerFromDb();
    vector<Person> sortScientistsFromDb(string sortMenu);
    vector<Computer> sortComputersFromDb(string sortMenu);
    vector<Person> searchScientistFromDb(string num, string search);
    vector<Computer> searchComputerFromDb(string num, string search);
    vector<pair<Person, Computer> > readLinkFromDb();
};


#endif // DATA_H
