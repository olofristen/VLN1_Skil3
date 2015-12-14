#include "domain.h"

Domain::Domain()    // Constructor, les úr gagnagrunninum í vektorana
{
    v = DB.readScientistFromDb();
    ve = DB.readComputerFromDb();
    vLink = DB.readLinkFromDb();
}

int Domain::scientistsSize()
{
    return v.size();
}
int Domain::computersSize()
{
    return ve.size();
}

int Domain::linkSize()
{
    return vLink.size();
}

void Domain::addNewPerson(string name, string gender, int birthYear, int deathYear, string bio)
{     // Bætir nýrri persónu inn i vektorinn...
    Person newP = Person(name, gender, birthYear, deathYear, bio);
    newP.setId(DB.addNewScientist(newP));
    v.push_back(newP);
}

void Domain::addNewComputer(string name, int buildYear, string type, bool wasBuilt, string info)
{     // Bætir nýrri tölvu inn i vektorinn...
    Computer newC = Computer(name, type, wasBuilt, buildYear, info);
    newC.setId(DB.addNewComputer(newC));
    ve.push_back(newC);
}

vector<Computer> Domain::getCompFromLinks(int pID)
{   // Sæki tölvu úr link-vektornum fyrir viðeigandi ID á Person
    vector<Computer> comp;
    for(unsigned int i = 0; i < vLink.size(); i++) {
        if(pID == vLink[i].first.getId()) {
            comp.push_back(vLink[i].second);
        }
    }
    return comp;
}
vector<Person> Domain::getSciFromLinks(int cID)
{   // Sæki hér vísindamann úr link-vektornum fyrir viðeigandi ID á Computer
    vector<Person> comp;
    for(unsigned int i = 0; i < vLink.size(); i++) {
        if(cID == vLink[i].second.getId()) {
            comp.push_back(vLink[i].first);
        }
    }
    return comp;
}

bool Domain::removeScientist(Person p)
{
    bool success = DB.removeScientist(p);
    v = DB.readScientistFromDb();
    return success;
}


bool Domain::removeComputer(Computer c)
{
    bool success = DB.removeComputer(c);
    ve = DB.readComputerFromDb();
    return success;
}

vector<Person> Domain::returnAllScientists()    // Skilar öllum Person-vektornum
{
    return v;
}

vector<Computer> Domain::returnAllComputers()   // Skilar öllum Computer-vektornum
{
    return ve;
}
vector<pair<Person, Computer> > Domain::returnAllLinks()       // Skilar öllum tengingunum
{
    return vLink;
}


bool Domain::addNewLink(Person p, Computer c)   // Linknar saman Person og Computer fyrir gagnagrunninn og pair-vektorinn...
{
    pair<Person, Computer> link = make_pair(p, c);
    bool success = DB.addNewLink(link);
    if(success)
    {
        cout << "That worked!" << endl;
        vLink.push_back(link);      // Hoppum yfir þetta ef við finnum parið nú þegar í vektornum
    }
    else
    {
        cout << endl << "Found duplicate link! This command was not confirmed."  << endl;
    }
    return success;
}


vector<Person> Domain::sortAndDisplayScientist(string sortMenu)
{        // sorterar vektorinn...
    return DB.sortScientistsFromDb(sortMenu);
}

vector<Computer> Domain::sortAndDisplayComputer(string sortMenu)
{        // sorterar vektorinn...
    return DB.sortComputersFromDb(sortMenu);
}

vector<Person> Domain::searchStringScientist(string num, string search)
{       // leitar í vektornum...
    return DB.searchScientistFromDb(num, search);
}

vector<Computer> Domain::searchStringComputer(string num, string search)
{       // leitar í vektornum...
    return DB.searchComputerFromDb(num, search);
}
