#include <algorithm>
#include "WideFlatBox.h"

WideFlatBox::WideFlatBox(double capacity) : Box(capacity) {
}

void WideFlatBox::insert(Object object) {
	if(getContentSize()+object.getSize() <= getCapacity()) {
		objects.push_back(object);
		setContentSize(getContentSize()+object.getSize());
	} else {
		throw ObjectDoesNotFitException();
	}
}

const Object& WideFlatBox::next() const {
	return objects[0];
}

void WideFlatBox::sortObjects() {
	sort(objects.begin(), objects.end());
}


void WideFlatBox::remove(Object object) {
    int pos = objectPos(object);

    if(pos == -1) throw InaccessibleObjectException(object);

    setContentSize(getContentSize() - object.getSize());
    objects.erase(objects.begin()+pos);
}

int WideFlatBox::objectPos(Object object) {
    auto it = find(objects.begin(), objects.end(), object);

    return it != objects.end() ? (int)(it - objects.begin()) : -1;
}
