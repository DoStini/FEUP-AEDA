//
// Created by andre on 10/25/2020.
//

#ifndef AEDA2021_P04_CLIENTDOESNOTEXIST_H
#define AEDA2021_P04_CLIENTDOESNOTEXIST_H


#include <exception>
#include <string>
#include <utility>

class ClientDoesNotExist {
    private:
        std::string name;
    public:
        ClientDoesNotExist(std::string name): name(std::move(name)){}
        std::string getName() {return name;}
};


#endif //AEDA2021_P04_CLIENTDOESNOTEXIST_H
