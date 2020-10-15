#include "zoo.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
using namespace std;

unsigned Zoo::numAnimals() const {
    return animals.size();
}

unsigned Zoo::numVeterinarians() const {
    return veterinarians.size();
}

void Zoo::addAnimal(Animal *a1) {
    animals.push_back(a1);
}

string Zoo::getInfo() const {
    ostringstream os;
    for(auto & anim : animals){
        os << anim->getInfo() << endl;
    }
    return os.str();
}

template <class T>
class Comp{
    T value;
public:
    Comp(T val) : value(val) {}
    bool operator()(Animal * animal){
        return animal->getName() == value;
    }
};

bool Zoo::isYoung(string nameA) {
    Comp<string> comp(std::move(nameA));
    auto it = std::find_if(animals.begin(), animals.end(), comp);

    return it != animals.end() && (*it)->isYoung();
}

void Zoo::allocateVeterinarians(istream &isV) {
    string name;
    int id;
    while(std::getline(isV, name)){
        isV >> id;
        Veterinary * vet = new Veterinary(name, id);
        veterinarians.push_back(vet);
        isV.ignore(); // Removing "" garbage
    }
    reallocateVeterinarians();
}

void Zoo::reallocateVeterinarians() {
    for (int i = 0; i < animals.size(); ++i) {
        animals[i]->setVeterinary(veterinarians[i % veterinarians.size()]);
    }
}

template <class T>
class VetComp{
    T value;
public:
    VetComp(T val) : value(val){};
    bool operator ()(Veterinary * vet){
        return vet->getName() == value;
    }
};

bool Zoo::removeVeterinary(string nameV) {
    VetComp<string> comp(std::move(nameV));
    auto it = std::find_if(veterinarians.begin(), veterinarians.end(), comp);

    if (it == veterinarians.end()) return false;

    Veterinary * vet = *it;
    veterinarians.erase(it);
    delete vet;
    reallocateVeterinarians();
    return true;
}

int Zoo::getAge() const {

    int total = 0;

    for(auto & anim : animals){
        total += anim->getAge();
    }

    return total;
}

bool Zoo::operator<(Zoo &zoo2) const {
    return this->getAge() < zoo2.getAge();
}

Zoo::~Zoo() {
    for(auto & vet : veterinarians) delete vet;
}
