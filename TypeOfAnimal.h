// Copyright 2015 <Anna Simakova>
#pragma once
#include "Animals.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "AlrExist.h"
#include "Coordinates.h"
#include "Probability.h"
#include <list>


using std::cin;
using std::cout;
using std::ostream;
using std::endl;
using std::exception;
using std::list;
using std::find;
using std::advance;

class Type {
private:
    char type;
    double p;
    list<Animals> pList;
public:
    ~Type();
    Type(char type);
    Type(char type, double p);
    void AddAnimals(const Animals& Animals);
    void printType();
    void delAllType();
    void DeleteType(char type);
    char GetType();
    void SetType(char type);
    double GetP() const;
    void SetP(double p);
    Type(const Type& type);
    const Type& operator =(const Type& Type);
    Animals& Get(int iter);
    const bool operator ==(const Type& Type);
    bool has(const Animals& anim);
};