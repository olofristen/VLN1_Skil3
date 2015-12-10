#ifndef DOMAIN_H
#define DOMAIN_H

#include "data.h"
#include <algorithm>
//#include <cstdlib>

class Domain
{

// Domain-klasinn geymir vektor með Person-klösum og sér um að umraða, leita í og bæta í hann.  Geymir Database-klasa og
// kemur gögnunum þannig á milli notendaviðmótsins og gagnagrunnsins.

private:

    vector<Person> v;
    vector<Computer> ve;
    vector<pair<Person, Computer> > vLink;
    Database DB;

public:
    Domain();
    void addNewPerson(string name, string gender, int birthYear, int deathYear, string bio);
    void addNewComputer(string name, int buildYear, string type, bool wasBuilt, string info);

    pair<Person, Computer> addNewLink(int pInd, int cInd);
    vector<Person> sortAndDisplayScientist(string sortMenu);
    vector<Computer> sortAndDisplayComputer(string sortMenu);
    vector<Person>  searchStringScientist(string num, string search);
    vector<Computer>  searchStringComputer(string num, string search);
    vector<Computer> getCompFromLinks(int pID);
    vector<Person> getSciFromLinks(int cID);

    vector<pair<Person, Computer> > returnAllLinks();
    vector<Person> returnAllScientists();
    vector<Computer> returnAllComputers();
    int size();
    int scientistsSize();
    int computersSize();
    int linkSize();


};


#endif // DOMAIN_H
