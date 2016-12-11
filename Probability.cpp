// Copyright 2016 <Anna Simakova>
#include "Probability.h"
#include <string>


Probability::Probability() :exception() {
    msg = "Probability should lie in the interval (0;100]";
}
const char * Probability::what() const throw() {
    return msg.c_str();
}