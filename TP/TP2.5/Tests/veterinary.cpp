#include "veterinary.h"
#include <sstream>
using namespace std;

/**
 * Constructor for the class Veterinary
 *
 * @param nome - Name of the vet
 * @param cod - Numerical code of the vet
 */
Veterinary::Veterinary(string nome, int cod){
    this->name = nome;
    this->codOrder = (long) cod;
}

/**
 * Returns the name of the veterinary
 *
 * @return name - name of veterinary
 */
string Veterinary::getName() const {
    return name;
}

/**
 * Function to retrieve info about the vet
 *
 * @return The info of the vet in the format "Name, Code"
 */
string Veterinary::getInfo() const {
    stringstream ss;
    ss << name << ", " << codOrder;
    return ss.str();
}


