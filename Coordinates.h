// Copyright 2016 <Anna Simakova>
#pragma once
#include <exception>
#include <string>
#include <stdlib.h>

using ::std::string;
using ::std::exception;

class Coordinates:public exception {
    string msg;

public:
    explicit Coordinates();
    const char* what() const throw();
};