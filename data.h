#ifndef DATA_H
#define DATA_H

#include "person.h"
#include "computer.h"
#include <vector>
#include <fstream>
#include <QtDebug>
#include <QtSql>
#include <ctime>

class Database
{

// Klasi fyrir gagnalagið.  Bætir Person, link og computer út í gagnagrunn og skilar úr grunninum í vektor.
// Hér fer umröðun og leitun fram, SQL skipanir notaðar til að stýra gagnagrunninum.

private:
    QSqlDatabase db;
public:
    Database();
    ~Database();
    int addNewScientist(Person P);
    int addNewComputer(Computer C);
    bool addNewLink(pair<Person, Computer> link);
    bool removeLink(Person p, Computer c);

    vector<Person> readScientistFromDb();
    vector<Computer> readComputerFromDb();
    vector<Person> sortScientistsFromDb(string sortMenu);
    vector<Computer> sortComputersFromDb(string sortMenu);
    vector<Person> searchScientistFromDb(string num, string search);
    vector<Computer> searchComputerFromDb(string num, string search);
    vector<pair<Person, Computer> > searchForLink(string type, string search);
   // vector<pair<Person, Computer> > searchForLink(string search);
    vector<pair<Person, Computer> > readLinkFromDb();
    vector<Person> filterScientistFromDb(string dropDownValue, string search);
    vector<Computer> filterComputerFromDb(string dropDownValue, string search);

    bool removeScientist(Person p);
    bool removeComputer(Computer c);
};


#endif // DATA_H
