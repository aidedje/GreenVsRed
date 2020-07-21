#include "Apple.h"

//Default constructor
Apple::Apple() {
    setColor(0);
}

//Constructor
Apple::Apple(int _color) {
    setColor(_color);
}

//setter and getter
void Apple::setColor(int _color) {
    this->color = _color;
}

int Apple::getColor() const {
    return this->color;
}

// output function
ostream& operator<<(ostream& os, Apple& a){
    os << a.getColor() << " ";
    return os;
}
