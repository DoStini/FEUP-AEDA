#ifndef FLEET_H_
#define FLEET_H_

#include <vector>
#include "vehicle.h"
using namespace std;

class Fleet {
	vector<Vehicle *> vehicles;
public:
    void addVehicle(Vehicle *v1);
    int numVehicles() const;
    int lowestYear() const;
    vector<Vehicle *> getVehicles() const;
    float totalTax() const;
	friend ostream & operator<<(ostream & o, const Fleet & f);
	vector<Vehicle *> operator () (int yearM) const;
	unsigned removeOldVehicles(int y1);
};


#endif /*FLEET_H_*/
