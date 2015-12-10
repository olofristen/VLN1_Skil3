#include "domain.h"

Domain::Domain()
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
{
    vector<Computer> comp;
    for(unsigned int i = 0; i < vLink.size(); i++) {
        if(pID == vLink[i].first.getId()) {
            comp.push_back(vLink[i].second);
        }
    }
    return comp;
}
vector<Person> Domain::getSciFromLinks(int cID)
{
    vector<Person> comp;
    for(unsigned int i = 0; i < vLink.size(); i++) {
        if(cID == vLink[i].second.getId()) {
            comp.push_back(vLink[i].first);
        }
    }
    return comp;
}

vector<Person> Domain::returnAllScientists()
{
    return v;
}

vector<Computer> Domain::returnAllComputers()
{
    return ve;
}
vector<pair<Person, Computer> > Domain::returnAllLinks()
{
    return vLink;
}

pair<Person, Computer> Domain::addNewLink(int pInd, int cInd)   // Setur linknar saman Person og Computer fyrir database og pair vektor!
{
    pair<Person, Computer> link = make_pair(v[pInd],ve[cInd]);
    for(unsigned int i = 0; i < vLink.size(); i++)
    {
        if((vLink[i].first.getId() == link.first.getId()) && (vLink[i].second.getId() == link.second.getId()))
        {
            cout << endl << "Found duplicate link! This command was not confirmed."  << endl;
            return link;
        }
     }
    vLink.push_back(link);      // Hoppum yfir þetta ef við finnum parið nú þegar í vektornum
    DB.addNewLink(link);
    return link;
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
