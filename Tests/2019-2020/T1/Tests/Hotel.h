#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_

#include <vector>
#include <list>
#include <numeric>

class NoSuchFloorException : std::exception {
public:
    NoSuchFloorException(int floor) : floor(floor){}
    const char * what() const noexcept override{
        return "No such floor";
    }
    int getFloor() const{
        return floor;
    }
private:
    int floor;
};



template <class Chamber>
class Hotel {
	std::vector<Chamber *> chambers;
	const unsigned int maxCapacity;
	const std::string city;
    std::list<Chamber> reservationsDone;
public:
	Hotel(int size, std::string municipality);
	~Hotel();
	std::vector<Chamber *> getChambers() const;
	int chamberPos(std::string code, int floor) const;
	unsigned int numChambers();
	void setChambers(std::vector<Chamber *> chambers);
	int getCapacity() const;
    std::list<Chamber> getReservationsDone() const;
	bool addChamber(Chamber *chamber);
    void addReservationDone(Chamber chamber);
    Chamber* removeChamber(std::string code, int floor);
	float avgArea(int floor) const;
	void sortChambers();
	bool doReservation(std::string code, int floor);
    std::list<Chamber> roomsNeverReserved() const;
};

class NoSuchChamberException {
public:
	NoSuchChamberException() { }
};

template <class Chamber>
Hotel<Chamber>::Hotel(int size, std::string municipality) : maxCapacity(size), city(municipality) {
}

template <class Chamber>
Hotel<Chamber>::~Hotel(){
	typename std::vector<Chamber *>::const_iterator it;
	for (it=chambers.begin(); it!=chambers.end(); it++) {
		delete *it;
	}
}

template<class Chamber>
std::vector<Chamber *> Hotel<Chamber>::getChambers() const {
	return chambers;
}

template<class Chamber>
void Hotel<Chamber>::setChambers(std::vector<Chamber*> chambers) {
	this->chambers = chambers;
}

template<class Chamber>
int Hotel<Chamber>::getCapacity() const {
	return maxCapacity;
}

template<class Chamber>
void Hotel<Chamber>::addReservationDone(Chamber chamber) {
    reservationsDone.push_back(chamber);
}

template<class Chamber>
std::list<Chamber> Hotel<Chamber>::getReservationsDone() const {
    return reservationsDone;
}

//------------------------------------------------------
//------------------------------------------------------


template<class Chamber>
bool Hotel<Chamber>::addChamber(Chamber *chamber) {
    if(maxCapacity == numChambers() ||
        std::find_if(chambers.begin(),
                  chambers.end(),
                  [chamber](Chamber * curr){
                        return *curr == *chamber;
                  }) != chambers.end()) return false;


    chambers.push_back(chamber);
    return true;
}


template<class Chamber>
void Hotel<Chamber>::sortChambers() {
    std::sort(chambers.begin(),
              chambers.end(),
              [](Chamber * ptr1, Chamber * ptr2){
                    return *ptr1 < *ptr2;
              });
}

template<class Chamber>
Chamber* Hotel<Chamber>::removeChamber(std::string code, int floor) {

    int pos =  chamberPos(code, floor);

    if(pos == -1) throw NoSuchChamberException();

    Chamber * out = chambers[pos];
    chambers.erase(chambers.begin() + pos);
    return out;
}

template<class Chamber>
float Hotel<Chamber>::avgArea(int floor) const {
    float acc = 0.0f;
    int counter = 0;
    for (const auto * room : chambers){
        if(room->getFloor() == floor) {
            acc += room->getArea();
            counter ++;
        }
    }

    if(counter == 0) throw NoSuchFloorException(floor);

    return acc/(float)counter;
}

template<class Chamber>
bool Hotel<Chamber>::doReservation(std::string code, int floor){

    int pos =  chamberPos(code, floor);

    if(pos == -1 || chambers[pos]->getReservation()) return false;

    chambers[pos]->setReservation(true);
    reservationsDone.push_back(*chambers[pos]);

    return true;
}

//TODO
template<class Chamber>
std::list<Chamber> Hotel<Chamber>::roomsNeverReserved() const {
    std::list<Chamber> res;
    auto its = reservationsDone.begin();
    auto ite = reservationsDone.end();
    for(const auto * ptr : chambers){
        auto itc = its;
        while(itc != ite){
            if(*itc == *ptr) break;
            itc++;
        }
        if(itc == ite) res.push_back(*ptr);
    }

    return res;
}

template<class Chamber>
unsigned int Hotel<Chamber>::numChambers() {
    return chambers.size();
}

template<class Chamber>
int Hotel<Chamber>::chamberPos(std::string code, int floor) const {
    auto it = std::find_if(chambers.begin(),
                           chambers.end(),
                           [floor, code](Chamber * ptr){
                               return ptr->getCode() == code && ptr->getFloor() == floor;
                           });
    if(it == chambers.end()) return -1;
    return it - chambers.begin();
}


#endif /* SRC_HOTEL_H_ */
