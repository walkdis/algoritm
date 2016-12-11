// Copyright 2016 <Anna Simakova>
#include "WrongEntr.h"
#include <string>


WrongEntr::WrongEntr() :exception() {
    msg = "Mistake! Number of values must be a multiple of 4";
}
const char * WrongEntr::what() const throw() {
    return msg.c_str();
}