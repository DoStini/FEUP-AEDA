#include "animal.h"
#include <sstream>
#include <utility>
using namespace std;

int Animal::youngest = -1;

Animal::Animal(string name, int age){
    this->name = std::move(name);
    this-> age = age;
    if (age < Animal::getYoungest() || Animal::getYoungest() == -1){
        Animal::youngest = age;
    };
}

string Animal::getName() const {
	return name;
}

int Animal::getAge() const {
    return age;
}

int Animal::getYoungest(){
    return Animal::youngest;
}

void Animal::setVeterinary(Veterinary *vet) {
    this->vet = vet;
}

Veterinary *Animal::getVeterinary() const {
    return vet;
}


Dog::Dog(string name, int age, string breed) : Animal(name, age){
    this->breed = std::move(breed);
}

bool Dog::isYoung() const {
    return age < 5;
}

string Dog::getInfo() const {
    ostringstream os;
    os << name << ", " << age << ", " << vet->getInfo() << ", " << breed;
    return os.str();
}

Flying::Flying(int maxv, int maxa) : maxAltitude(maxa), maxVelocity(maxv) {}

int Flying::getMaxV() const {
    return maxVelocity;
}

int Flying::getMaxA() const {
    return maxAltitude;
}

Bat::Bat(string name, int age, int maxv, int maxa) : Animal(name, age), Flying(maxv, maxa) {}

bool Bat::isYoung() const {
    return age < 4;
}

string Bat::getInfo() const {
    ostringstream os;
    os << name << ", " << age << ", " << vet->getInfo() << ", " << getMaxV() << ", " << getMaxA();
    return os.str();
}
