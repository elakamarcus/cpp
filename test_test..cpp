#include <iostream>
#include <math.h>
#include <vector>

using std::cout;
using std::endl;

struct Vector {
    float x, y, z;
};

Vector vectorcross(Vector *v1, Vector *v2){
    struct Vector v3 = {(v1->y * v2->z) - (v1->z * v2->y), (v1->z*v2->x) - v1->x * v2->z, (v1->x*v2->y) - v1->y * v2->x };
    return v3;
}

Vector rotatevector2d(Vector *v1, float angle){
    Vector vr = {v1->x * cos(angle) - v1->y*sin(angle), v1->x*sin(angle) + v1->y*cos(angle), v1->z};
    return vr;
}

float vectorLen(Vector *v1){
    float vlen = sqrt(pow(v1->x,2) + pow(v1->y,2) + pow(v1->z,2));
    return vlen;
}

int main(){

    struct Vector v1 = {1.0, 2.0, 3.0};
    struct Vector v2 = {4.0, 5.0, 4.0};
    Vector v3 = vectorcross(&v1, &v2);
    float v3len = vectorLen(&v3);
    struct Vector v4 = vectorcross(&v2, &v1); 
    
    return 0;
}