// Copyright 2016 <Anna Simakova>
#include "Animals.h"

Animals::Animals(double _x, double _y, char _type){
    x = _x;
    y = _y;
    type = _type;
    p = 1;
};

Animals::Animals(double _x, double _y, char _type, double _p){
    x = _x;
    y = _y;
    type = _type;
    p = _p;
};

Animals::~Animals(){};

ostream& operator<<(ostream& stream, const Animals& anim){
    stream << "type of animal: " << anim.type << "X of animal: " << anim.x << "Y of animal: " << anim.y << endl;
    return stream;
};

double Animals::GetX(){
    return x;
};

double Animals::GetY(){
    return y;
};

char Animals::GetType(){
    return type;
};

double Animals::GetP(){
    return p;
};
double Animals::SetX(double _x){
    x = _x;
};

double Animals::SetY(double _y){
    y = _y;
};

char Animals::SetType(char _type){
    type = _type;
};

double Animals::SetP(double _p){
    p = _p;
};

Animals::Animals(const Animals& anim) {
    x = anim.x;
    y = anim.y;
    type = anim.type;
    p = anim.p;
}

const Animals& Animals::operator =(const Animals& anim) {
    if (this != &anim) {
        x = anim.x;
        y = anim.y;
        type = anim.type;
        p = anim.p;
    }
    return (*this);
}

bool Animals::operator ==(const Animals& anim) const {
    return (((*this).x == anim.x) && ((*this).y == anim.y) &&
        ((*this).type == anim.type) && ((*this).p == anim.p));
}
