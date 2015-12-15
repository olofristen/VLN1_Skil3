#include "computer.h"

bool Computer::operator < (const Computer &r)
{
     return this->name < r.name;
}

Computer::Computer()
{
    ID = 0;
    name = " ";
    type = " ";
    wasBuilt = false;
    buildYear = 0;
    info = " ";
}

Computer::Computer(string name, string type, bool wasBuilt, int buildYear, string info)
{
    this->name = name;
    this->type = type;
    this->wasBuilt = wasBuilt;
    this->buildYear = buildYear;
    this->info = info;
}

Computer::Computer(QSqlQuery q)     // Þvílík snilld...
{
    readData(q);
}

string Computer::getName()
{
    return name;
}

int Computer::getBuildYear()
{
    return buildYear;
}

string Computer::getType()
{
    return type;
}

bool Computer::getWasBuilt()
{
    return wasBuilt;
}

string Computer::getInfo()
{
    return info;
}

int Computer::getId()
{
    return ID;
}

ostream& operator << (ostream& out, const Computer& C)
{
    out << "Name: " << C.name << endl
        << "Type: " << C.type << endl;
    if(C.wasBuilt == false)
    {
        out << "Built: This computer was never built, but it was documented in " << C.buildYear << endl;
    }
    else
    {
        out << "Built: This computer was built in " << C.buildYear << endl;
    }
    out << endl;
    out << "Info: " << C.info << endl;

    return out;
}

void Computer::readData(QSqlQuery query)
{
    ID = query.value("ID").toInt();
    name = query.value("Name").toString().toStdString();
    buildYear = query.value("BuildYear").toInt();
    type = query.value("Type").toString().toStdString();
    wasBuilt = query.value("WB").toBool();
    info = query.value("Info").toString().toStdString();
}

void Computer::setId(int id)
{
    ID = id;
}
