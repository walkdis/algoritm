// Copyright 2016 <Anna Simakova>
#pragma once
#include <exception>
#include <string>
#include <stdlib.h>

using ::std::string;
using ::std::exception;

class AnimalAlrExist:public exception {
    string msg;

public:
    explicit AnimalAlrExist();
    const char* what() const throw();
};