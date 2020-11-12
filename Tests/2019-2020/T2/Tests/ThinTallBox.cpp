#include "ThinTallBox.h"
#include "WideFlatBox.h"

ThinTallBox::ThinTallBox(double capacity) : Box(capacity) {
}

ThinTallBox::ThinTallBox(double capacity, stack<Object> objects, double content_size) : Box(capacity) {
	this->objects = objects;
	this->setContentSize(content_size);
}

stack<Object> ThinTallBox::getObjects() const {
    return objects;
}

void ThinTallBox::remove(Object object) {
	Object next_object = next();
	if(!(next_object == object)) {
		throw InaccessibleObjectException(object);
	} else {
		setContentSize(getContentSize()-next_object.getSize());
		objects.pop();
	}
}

const Object& ThinTallBox::next() const {
	return objects.top();
}


void ThinTallBox::insert(Object object) {
    if(getContentSize() + object.getSize() > getCapacity()) throw ObjectDoesNotFitException();

    objects.push(object);
    setContentSize(getContentSize() + object.getSize());
}

void ThinTallBox::sortObjects() {
    WideFlatBox aux(this->getCapacity());

    while (!empty()){
        Object temp = next();
        remove(temp);
        aux.insert(temp);
    }

    aux.sortObjects();

    while(!aux.empty()){
        Object temp = aux.next();
        aux.remove(temp);
        insert(temp);
    }
}
