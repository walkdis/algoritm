// Copyright 2016 <Anna Simakova>
#pragma once

#include "AlrExist.h"
#include "Coordinates.h"
#include <stdio.h>
#include <iostream>


using ::std::cin;
using ::std::cout;
using ::std::ostream;
using std::endl;

class Animals {
    double x;
    double y;


public:
    Animals(double x, double y);
    ~Animals();
    friend ostream& operator<<(ostream& stream, const Animals& anim);
    double GetX();
    double GetY();
    char GetType();
    double GetP();
    double SetX(double x);
    double SetY(double y);
    char SetType(char type);
    double SetP(double p);
    Animals(const Animals& anim);
    const Animals& operator =(const Animals& anim);
    bool operator ==(const Animals& anim) const;
};