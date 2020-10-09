#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
using namespace std;

class  Vehicle {
protected:
   string brand;
   int month, year;
public:
   Vehicle(string b, int m, int y);
   virtual ~Vehicle(){};
   int getYear() const;
   string getBrand() const;
   virtual int info() const = 0;
   virtual int info(std::ostream & o) const = 0;
   bool operator < (const Vehicle & v) const;
   virtual float calculateTax() const = 0;
};

class MotorVehicle: public Vehicle {
    string fuel; int cylinder;
public:
    MotorVehicle(string b, int m, int y,string f,int cyl);
    string getFuel() const;
    int getCyl() const;
    virtual int info() const = 0;
    virtual int info(std::ostream & o) const = 0;
    float calculateTax() const;
};


class Car: public MotorVehicle {
public:
    Car(string b, int m, int y, string f, int cyl);
    int info() const override;
    int info(ostream &o) const override;
};


class Truck: public MotorVehicle {
    int maximumLoad;
public:
    Truck(string b, int m, int y,string f, int cyl,int ml);
    int info() const override;
    int info(ostream &o) const override;
};


class Bicycle: public Vehicle {
    string type;
public:
    Bicycle(string b, int m, int y, string t);
    int info() const override;
    int info(ostream &o) const override;
    float calculateTax() const;
};

#endif /* VEHICLE_H_ */
