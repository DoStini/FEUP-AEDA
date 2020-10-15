#ifndef SRC_ANIMAL_H_
#define SRC_ANIMAL_H_

#include "veterinary.h"
#include <string>
using namespace std;

/**
 * Animal super class
 *
 * @param name - Name of the animal
 * @param age - Age of the animal
 * @param *vet - Pointer to the corresponding veterinary
 * @param youngest - Age of the youngest animal
 */
class Animal {
protected:
    string name;
    int age;
    Veterinary *vet;
    static int youngest;
public:
    Animal(string name, int age);
    virtual ~Animal(){};
    string getName() const;
    int getAge() const;
    Veterinary *getVeterinary() const;
    void setVeterinary(Veterinary *vet);
    static int getYoungest();
    virtual string getInfo() const = 0;  // info concerning name, age, name of the veterinary (if any)
    virtual bool isYoung() const = 0;
};

class Dog: public Animal {
    string breed;
public:
    Dog(string name, int age, string breed);
    bool isYoung() const override;
    string getInfo() const override;
};


class Flying {
    int maxVelocity;
    int maxAltitude;
public:
    Flying(int maxv, int maxa);
    int getMaxV() const;
    int getMaxA() const;
};


class Bat: public Animal, public Flying {
public:
    Bat(string name, int age, int maxv, int maxa);

    bool isYoung() const override;
    string getInfo() const override;
};

#endif /* SRC_ANIMAL_H_ */
