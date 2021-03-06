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
    bool addNewLink(Person p, Computer c);
    pair<Person, Computer> returnLinkFromNames(string pName, string cName);

    vector<Person> sortAndDisplayScientist(string sortMenu);
    vector<Computer> sortAndDisplayComputer(string sortMenu);
    vector<Person>  searchStringScientist(string num, string search);
    vector<Computer>  searchStringComputer(string num, string search);
    vector<pair<Person, Computer> > searchForLink(string type, string search);
//    vector<pair<Person, Computer> > searchForLink(string search);
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

    bool removeScientist(Person p);
    bool removeComputer(Computer c);
    bool removeLink(pair<Person, Computer> link);
};


#endif // DOMAIN_H
