/*
 * File:   RealNumber.cpp
 * Author: arnaldogaspar

 * Created on 23 de febrero de 2013, 18:09
 */


#include <cstdlib>
#include <iostream>
#include "math.h"
using namespace std;

#include "RealNumber.h"

RealNumber::RealNumber() {
}

RealNumber::RealNumber(const RealNumber& orig) {
}

RealNumber::~RealNumber() {
}

RealNumber RealNumber::operator>(const RealNumber &b){
	this->value+=b.value;
	return *this;
}

// suma explícita de una ruta
RealNumber RealNumber::operator+(const RealNumber &b){
	this->value+=b.value;
	cout << this->value << " + " << b.value << endl;
	return *this;
}
// resta de una ruta para hoy
RealNumber RealNumber::operator-(const RealNumber &b){
	this->value-=b.value;
	return *this;
}

RealNumber RealNumber::operator*(float m){
	this->value*=m;
	return *this;
}

float RealNumber::fitnessFunction(RealNumber &r){
	float x = r.value;
	float f = log(x) + 0.0000001;
	cout << "evaluating fitness function f(" << x << "): " << f << endl;
	return f;
}

void RealNumber::initRandomPosition(RealNumber &r){
	float f = (float)rand()/(float)RAND_MAX;
	r.value = f;
	//r.value = rand();
	cout << "init random position with value " << r.value << endl;
}
void RealNumber::initRandomVelocity(RealNumber &r){
	float f = (float)rand()/(float)RAND_MAX;
	r.value = f;
	//r.value = rand();
	cout << "init random velocity with value " << r.value << endl;
}

