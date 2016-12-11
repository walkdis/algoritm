// Copyright 2016 <Anna Simakova>
#pragma once

#include "AlrExist.h"
#include "Coordinates.h"
#include "Probability.h"
#include <stdio.h>
#include <iostream>


using ::std::cin;
using ::std::cout;
using ::std::ostream;
using std::endl;

class Animals {
    int x;
    int y;
    int p;
    int type;
    double distance;
    bool exist;


public:
    Animals();
    Animals(int type, int x, int y, int p);
    ~Animals();
    friend ostream& operator<<(ostream& stream, const Animals& anim);
    int GetX();
    int GetY();
    int GetP();
    int GetType();
    double GetDistance();
    bool GetExist();
    void SetX(int x);
    void SetY(int y);
    void SetP(int p);
    void SetType(int type);
    void SetDistance(double distance);
    void SetExist(bool ex);
    Animals(const Animals& anim);
    const Animals& operator =(const Animals& anim);
    bool operator ==(const Animals& anim) const;
    bool operator !=(const Animals& anim) const;
};