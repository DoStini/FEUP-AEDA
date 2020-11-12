#include <queue>
#include <cstdlib>
#include "counter.h"
#include "exceptions.h"
using namespace std;

//TODO
Client::Client() {
    numGifts = 1 + rand()%5;
}

//TODO
unsigned Client::getNumGifts() const {
    return numGifts;
}


//TODO
Counter::Counter(unsigned wt): wrappingTime(wt), nextLeave(0), actualTime(0), numAttendedClients(0) {
    nextEnter = rand()%20 + 1;
}

//TODO
unsigned Counter::getActualTime() const {
    return actualTime;
}

//TODO
unsigned Counter::getNextEnter() const {
    return nextEnter;
}

//TODO
unsigned Counter::getNumAttendedClients() const {
    return numAttendedClients;
}

//TODO
unsigned Counter::getWrappingTime() const {
    return wrappingTime;
}

//TODO
unsigned Counter::getNextLeave() const {
    return nextLeave;
}

//TODO
Client & Counter::getNextClient() {
    if(clients.empty()) throw EmptyQueue();
    return clients.front();
}

//TODO
void Counter::enter()
{
    Client client;
    if(clients.empty()) nextLeave = actualTime + wrappingTime * client.getNumGifts();
    clients.push(client);

    nextEnter = actualTime + rand()%20 + 1;

    std::cout << "new customer arrived with " << client.getNumGifts() << " gifts" << std::endl;

}

//TODO
void Counter::leave()
{
    Client * ptr;
    try {
        ptr = &getNextClient();
    } catch (EmptyQueue e) {
        e.getMsg();
    }
    clients.pop();
    numAttendedClients++;
    try {
        ptr = &getNextClient();
        nextLeave = actualTime + wrappingTime * ptr->getNumGifts();
    } catch (EmptyQueue e) {
        nextLeave = 0; // No more clients
    }
}

//TODO
void Counter:: nextEvent()
{
    if(nextEnter > nextLeave && nextLeave != 0){
        actualTime = nextLeave;
        leave();
    }
    else if(nextEnter < nextLeave || nextLeave == 0){
        actualTime = nextEnter;
        enter();
    }
    else{
        actualTime = nextEnter;
        enter();
        leave();
    }
}


//TODO
ostream & operator << (ostream & out, const Counter & c2)
{
     return out;
}


