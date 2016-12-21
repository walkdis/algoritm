// Copyright 2016 <Anna Simakova>
#include "Animals.h"

Animals::Animals(){
    x = 0;
    y = 0;
    type = 0;
    p = 100;
    distance = 0;
};

Animals::Animals(int _type, int _x, int _y, int _p){
    if ((_x < 0) || (_y < 0) || ((_x == 0) && (_y==0)))
        throw Coordinates();
    if ((_p <= 0) || (_p > 100))
        throw Probability();
    x = _x;
    y = _y;
    type = _type;
    p = _p;
    distance = 0;
    exist = 1;
};

Animals::~Animals(){};

ostream& operator<<(ostream& stream, const Animals& anim){
    stream << "X of animal: " << anim.x << "Y of animal: " << anim.y << "Type: " << anim.type << endl;
    return stream;
};

int Animals::GetX(){
    return x;
};

int Animals::GetY(){
    return y;
};

int Animals::GetP(){
    return p;
};

int Animals::GetType(){
    return type;
};

double Animals::GetDistance(){
    return distance;
}

bool Animals::GetExist(){
    return exist;
}

void Animals::SetX(int _x){
    x = _x;
};

void Animals::SetY(int _y){
    y = _y;
};

void Animals::SetP(int _p){
    p = _p;
};

void Animals::SetType(int _type){
    type = _type;
};

void Animals::SetDistance(double _distance){
    distance = _distance;
}

void Animals::SetExist(bool _exist) {
    exist = _exist;
}

Animals::Animals(const Animals& anim) {
    x = anim.x;
    y = anim.y;
    p = anim.p;
    type = anim.type;
    distance = anim.distance;
    exist = anim.exist;
}

const Animals& Animals::operator =(const Animals& anim) {
    if (this != &anim) {
        x = anim.x;
        y = anim.y;
        p = anim.p;
        type = anim.type;
        distance = anim.distance;
        exist = anim.exist;
    }
    return (*this);
}

bool Animals::operator ==(const Animals& anim) const {
    return (((*this).x == anim.x) && ((*this).y == anim.y) && ((*this).type == anim.type) && ((*this).p == anim.p));
}

bool Animals::operator !=(const Animals& anim) const {
    return (((*this).x != anim.x) || ((*this).y != anim.y) || ((*this).type != anim.type) || ((*this).p != anim.p));
}