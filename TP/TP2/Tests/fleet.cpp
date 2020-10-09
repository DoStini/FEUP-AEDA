#include "fleet.h"
#include <string>
#include <algorithm>

using namespace std;

vector<Vehicle *> Fleet::getVehicles() const {
    return vehicles;
}

void Fleet::addVehicle(Vehicle *v1){
    vehicles.push_back(v1);
}

int Fleet::numVehicles() const{
    return vehicles.size();
}

bool comp(Vehicle * v1, Vehicle * v2){
    return v1->getYear() < v2->getYear();
}

int Fleet::lowestYear() const{
    return !vehicles.empty() ? (*std::min_element(vehicles.begin(),
                                                     vehicles.end(),
                                                     [](Vehicle * v1, Vehicle * v2){return *v1 < *v2;}
                                                     ))->getYear()
                                : 0;
}

ostream &operator<<(ostream &o, const Fleet &f) {
    for(auto & ptr : f.getVehicles()){
        ptr->info(o);
    }
    return o;
}

class Comp{
    int comparer;
public:
    Comp(int val) : comparer(val){};
    bool operator ()(Vehicle * value){
        return value->getYear() == comparer;
    }

};

class LessThanEq{
    int comparer;
public:
    LessThanEq(int val) : comparer(val){};
    bool operator ()(Vehicle * value){
        return value->getYear() <= comparer;
    }

};

vector<Vehicle *> Fleet::operator()(int yearM) const {
    std::vector<Vehicle *> out(vehicles.size());
    Comp comparer(yearM);
    auto it = std::copy_if(vehicles.begin(), vehicles.end(), out.begin(), comparer);
    out.erase(it, out.end());
    return out;
}

float Fleet::totalTax() const {
    float tax = 0;

    for (auto & curr : vehicles){
        tax += curr->calculateTax();
    }
    return tax;
}

unsigned Fleet::removeOldVehicles(int y1) {
    LessThanEq lesseq(y1);
    auto it = std::remove_if(vehicles.begin(), vehicles.end(), lesseq);

    unsigned out = vehicles.end() - it;

    vehicles.erase(it, vehicles.end());

    return out;
}
