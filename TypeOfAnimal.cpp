// Copyright 2016 <Anna Simakova>
#include "TypeOfAnimal.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>

Type::~Type() {
    delAllType();
}
Type::Type(char _type) {
    type = _type;
    p = 1;
}
Type::Type(char _type, double _p) {
    if ((_p <= 0) || (_p > 1))
        throw Probability();
    type = _type;
    p = _p;
}
void Type::AddAnimals(const Animals& anim) {
    if (has(anim))
        throw AnimalAlrExist();
    pList.push_back(anim);
}

void Type::printType() {
    cout << type << " ";
    for (list<Animals>::iterator it = pList.begin(); it != pList.end(); ++it)
        cout << (*it);
}
void Type::delAllType() {
    pList.clear();
}

bool Type::has(const Animals& anim) {
    auto it = find(pList.begin(), pList.end(), anim);
    return it != pList.end();
}
Type::Type(const Type& type1) {
    type = type1.type;
    p = type1.p;
    pList = type1.pList;
}
const Type& Type::operator =(const Type& _type) {
    if (this != &_type) {
        type = _type.type;
        p = _type.p;
        pList = _type.pList;
    }
    return (*this);
}
Animals& Type::Get(int iter) {
    list<Animals>::iterator it = pList.begin();
    advance(it, iter);
    return (*it);
}
const bool Type::operator ==(const Type& Type) {
    return (((*this).type == Type.type) &&
        ((*this).p == Type.p) && ((*this).pList == Type.pList));
}
