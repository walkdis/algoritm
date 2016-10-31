// Copyright 2016 <Anna Simakova>
#include "Coordinates.h"
#include <string>


Coordinates::Coordinates() :exception() {
    msg = "Please, enter non-negative coordinates ((0, 0) also unavailable)";
}
const char * Coordinates::what() const throw() {
    return msg.c_str();
}