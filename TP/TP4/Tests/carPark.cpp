#include "carPark.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>
using namespace std;

CarPark::CarPark(unsigned cap, unsigned nMaxCli): capacity(cap), numMaxClients(nMaxCli)
{
    freePlaces=cap;
}

vector<InfoCard> CarPark::getClients() const
{
    return clients;
}

unsigned CarPark::getNumPlaces() const
{
    return capacity;
}

unsigned CarPark::getNumOccupiedPlaces() const
{
    return capacity-freePlaces;
}

unsigned CarPark::getNumMaxClients() const
{
    return numMaxClients;
}

unsigned CarPark::getNumClients() const
{
    return clients.size();
}

// TODO
int CarPark::clientPosition(const string & name) const
{
    InfoCard temp; temp.name = name;
    return sequentialSearch<InfoCard>(clients, temp);
}

// TODO
unsigned CarPark::getFrequency(const string &name) const
{
    int pos = clientPosition(name);
    if (pos == -1) throw ClientDoesNotExist(name);
    return clients[pos].frequency;
}

// TODO: to modify
bool CarPark::addClient(const string & name)
{
    if (clients.size() == numMaxClients) return false;
    if (clientPosition(name) != -1) return false;
    InfoCard info;
    info.name=name;
    info.frequency=0;
    info.present=false;
    clients.push_back(info);
    return true;
}

// TODO: to modify
bool CarPark::removeClient(const string & name)
{
    for (vector<InfoCard>::iterator it = clients.begin(); it != clients.end(); it++)
        if ( (*it).name == name ) {
            if ( (*it).present == false ) {
                clients.erase(it);
                return true;
            }
            else return false;
        }
    return false;
}

// TODO: to modify
bool CarPark::enter(const string & name)
{
    if (freePlaces == 0) return false;
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == true) return false;
    clients[pos].present = true;
    clients[pos].frequency++;
    freePlaces--;
    return true;
}

// TODO: to modify
bool CarPark::leave(const string & name)
{
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == false) return false;
    clients[pos].present = false;
    freePlaces++;
    return true;
}


// TODO
InfoCard CarPark::getClientAtPos(unsigned p) const
{
    if(p >= clients.size()) throw PositionDoesNotExist(p);
    return clients[p];
}

// TODO
void CarPark::sortClientsByFrequency()
{
    insertionSort(clients);
}

// TODO
void CarPark::sortClientsByName()
{
    std::sort(clients.begin(), clients.end(), [](const InfoCard & c1, const InfoCard & c2){return c1.name < c2.name;});
}

// TODO
vector<string> CarPark::clientsBetween(unsigned f1, unsigned f2)
{
    vector<string> names;
    sortClientsByFrequency();
    int pos1,pos2;
    for (const auto & cli : clients) {
        if(cli.frequency >= f1 && cli.frequency <= f2) names.push_back(cli.name);
    }


    return names;
}


// TODO
ostream & operator<<(ostream & os, const CarPark & cp)
{
    return os;
}

bool InfoCard::operator==(const InfoCard &rhs) const {
    return name == rhs.name;
}

bool InfoCard::operator<(const InfoCard &rhs) const{
    return frequency > rhs.frequency || (rhs.frequency == frequency && name < rhs.name);
}


