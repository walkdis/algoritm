// Copyright 2016 <Anna Simakova>
#include "AlrExist.h"
#include <string>


AnimalAlrExist::AnimalAlrExist(double x, double y) :exception() {
    string textx, texty;
    textx = x;
    texty = y;
    msg = "Animal with coordinates: " + textx + texty + " already exist";
}
const char * AnimalAlrExist::what() const throw() {
    return msg.c_str();
}
