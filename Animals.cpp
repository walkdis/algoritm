// Copyright 2016 <Anna Simakova>
#include "Animals.h"

Animals::Animals(double _x, double _y){
    if (((_x < 0) || (_y < 0)) || ((_x == 0) && (_y == 0)))
        throw Coordinates();
    x = _x;
    y = _y;
};

Animals::~Animals(){};

ostream& operator<<(ostream& stream, const Animals& anim){
    stream << "X of animal: " << anim.x << "Y of animal: " << anim.y << endl;
    return stream;
};

double Animals::GetX(){
    return x;
};

double Animals::GetY(){
    return y;
};


double Animals::SetX(double _x){
    x = _x;
};

double Animals::SetY(double _y){
    y = _y;
};


Animals::Animals(const Animals& anim) {
    x = anim.x;
    y = anim.y;
}

const Animals& Animals::operator =(const Animals& anim) {
    if (this != &anim) {
        x = anim.x;
        y = anim.y;
    }
    return (*this);
}

bool Animals::operator ==(const Animals& anim) const {
    return (((*this).x == anim.x) && ((*this).y == anim.y));
}