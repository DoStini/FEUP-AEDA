#include "packagingMachine.h"
#include <sstream>
#include <iomanip>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
    return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
    boxes.push(b1);
    return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
    return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
    return this->boxes;
}


unsigned PackagingMachine::loadObjects(vector<Object> &objs) {

    int counter = 0;

    for(auto it = objs.begin(); it != objs.end();){
        if(it->getWeight() <= boxCapacity){
            objects.push(*it);
            objs.erase(it);
            counter++;
        }
        else it++;
    }
    return counter;
}

Box PackagingMachine::searchBox(Object& obj) {

    int w = obj.getWeight();

    Box b;

    HeapBox copy;

    while (!boxes.empty()){
        if(boxes.top().getFree() >= w){
            b = boxes.top();
            boxes.pop();
            break;
        }
        copy.push(boxes.top());
        boxes.pop();
    }

    // Restoring state of original queue
    while (!copy.empty()){
        boxes.push(copy.top());
        copy.pop();
    }

    return b;
}

unsigned PackagingMachine::packObjects() {

    while(!objects.empty()){
        Object obj = objects.top(); objects.pop();
        Box bx = searchBox(obj);
        bx.addObject(obj);
        boxes.push(bx);
    }

	return boxes.size();
}

string PackagingMachine::printObjectsNotPacked() const {
    stringstream ss;

    HeapObj copy = objects;
    if(copy.empty()) ss << "No objects!\n";

    while(!copy.empty()){
        Object obj = copy.top(); copy.pop();
        ss << obj << '\n';
    }

	return ss.str();
}

Box PackagingMachine::boxWithMoreObjects() const {
	if(boxes.empty()) throw MachineWithoutBoxes();
    Box b;
	auto copy = boxes;

	while (!copy.empty()){
	    Box bx = copy.top(); copy.pop();
	    if(bx.getSize() > b.getSize()) b = bx;
	}

	return b;
}