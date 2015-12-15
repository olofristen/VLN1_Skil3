#ifndef DOMAIN_H
#define DOMAIN_H

#include "data.h"
#include <algorithm>
//#include <cstdlib>

class Domain
{

// Domain-klasinn geymir vektor með Person-klösum, vektor af Computer-klösum og vektor af pari af Person og Computer (link).
// Hann sér um að skila umröðunum og leitunum úr gagnagrunninum og upp í UI og einnig að bæta í grunninn.
// Geymir Database-klasa og kemur gögnunum þannig á milli notendaviðmótsins og gagnagrunnsins.

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
    vector<Person> filterScientist(string dropDownValue, string search);
    vector<Computer> filterComputer(string dropDownValue, string search);

    vector<pair<Person, Computer> > returnAllLinks();
    vector<Person> returnAllScientists();
    vector<Computer> returnAllComputers();
    int size();
    int scientistsSize();
    int computersSize();
    int linkSize();


};


#endif // DOMAIN_H
