// Copyright 2016 <Anna Simakova>
#include "AlrExist.h"
#include <string>


AnimalAlrExist::AnimalAlrExist() :exception() {
    msg = "Animal with such coordinates already exist";
}
const char * AnimalAlrExist::what() const throw() {
    return msg.c_str();
}