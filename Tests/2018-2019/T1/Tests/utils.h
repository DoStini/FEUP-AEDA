//
// Created by andre on 11/11/2020.
//

#ifndef AEDA1819_CI1_UTILS_H
#define AEDA1819_CI1_UTILS_H

#include <vector>
#include <algorithm>

using namespace std;


template <class T>
unsigned int numberDifferent(const vector<T> & v1){

    vector<T> temp;
    bool ret;
    for (const T & val : v1) {
        if(find(temp.begin(), temp.end(), val) == temp.end())
            temp.push_back(val);
    }
    return temp.size();
}


#endif //AEDA1819_CI1_UTILS_H
