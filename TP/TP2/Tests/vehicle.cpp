#include "vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(string b, int m, int y){
    brand = b;
    month = m;
    year = y;
}

string Vehicle::getBrand() const {
    return brand;
}

bool Vehicle::operator<(const Vehicle &v) const {
    return (this->year < v.year) || (this->year == v.year && this->month < v.month);
}

int Vehicle::getYear() const {
    return year;
}


MotorVehicle::MotorVehicle(string b, int m, int y,string f,int cyl) : Vehicle(std::move(b),m,y){
    fuel = std::move(f);
    cylinder = cyl;
}

string MotorVehicle::getFuel() const {
    return fuel;
}

int MotorVehicle::getCyl() const {
    return cylinder;
}

float MotorVehicle::calculateTax() const {

    if(fuel == "gas"){
        if(cylinder <= 1000)      return year > 1995 ? 14.56  : 8.10;
        else if(cylinder <= 1300) return year > 1995 ? 29.06  : 14.56;
        else if(cylinder <= 1750) return year > 1995 ? 45.15  : 22.65;
        else if(cylinder <= 2600) return year > 1995 ? 113.98 : 54.89;
        else if(cylinder <= 3500) return year > 1995 ? 181.17 : 87.13;
        else                      return year > 1995 ? 320.89 : 148.37;
    }
    else{
        if(cylinder <= 1500)      return year > 1995 ? 14.56  : 8.10;
        else if(cylinder <= 2000) return year > 1995 ? 29.06  : 14.56;
        else if(cylinder <= 3000) return year > 1995 ? 45.15  : 22.65;
        else                      return year > 1995 ? 113.98 : 54.89;
    }

}


Car::Car(string b, int m, int y, string f, int cyl) : MotorVehicle(std::move(b),m,y,std::move(f),cyl){};

int Car::info() const{
    std::cout << "Brand: " << brand << ", month: " << month << ", year: " << year << ", fuel: " << getFuel() << ", cylinder: " << getCyl() << endl;
    return 5;
}

int Car::info(ostream &o) const {
    o << "Brand: " << brand << ", month: " << month << ", year: " << year << ", fuel: " << getFuel() << ", cylinder: " << getCyl() << endl;
    return 5;
}


Truck::Truck(string b, int m, int y,string f, int cyl,int ml) : MotorVehicle(std::move(b),m,y,std::move(f),cyl), maximumLoad(ml){}

int Truck::info() const {
    std::cout << "Brand: " << brand << ", month: " << month << ", year: " << year << ", fuel: " << getFuel() << ", cylinder: " << getCyl() << ", load: " << maximumLoad << endl;
    return 6;
}

int Truck::info(ostream &o) const {
    o << "Brand: " << brand << ", month: " << month << ", year: " << year << ", fuel: " << getFuel() << ", cylinder: " << getCyl() << ", load: " << maximumLoad << endl;
    return 6;
};

Bicycle::Bicycle(string b, int m, int y, string t) : Vehicle(std::move(b),m,y), type(std::move(t)){}

int Bicycle::info() const {
    std:cout << "Brand: " << brand << ", month: " << month << ", year: " << year << ", type: " << type << endl;
    return 4;
}

int Bicycle::info(ostream &o) const {
    o << "Brand: " << brand << ", month: " << month << ", year: " << year << ", type: " << type << endl;
    return 4;
}

float Bicycle::calculateTax() const {
    return 0;
}

