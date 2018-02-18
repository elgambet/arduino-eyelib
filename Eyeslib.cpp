/*
  Eyeslib.h - Library for Ultrasonic distance measurement elegoo smart robot car v1.0
  Created by Pablo Gambetta December 2018
  Released into the public domain.
*/
#include "Arduino.h"
#include "Eyeslib.h"

int distance(int Echo, int Trig)
{
	digitalWrite(Trig, LOW);
	delayMicroseconds(2);
	digitalWrite(Trig, HIGH);
	delayMicroseconds(20);
	digitalWrite(Trig, LOW);
	float Fdistance = pulseIn(Echo, HIGH);
	Fdistance = Fdistance / 58;
	return (int)Fdistance;
};

Eyeslib::Eyeslib()
{
	this.middle = 0;
	this.left = 1;
	this.right = 2;
};

void Eyeslib::setEye(int echo, int trig, int eye)
{
	switch (eye)
	{
	case this.left:
		this.leftEcho = echo;
		this.leftTrig = trig;
		break;
	case this.right:
		this.rightEcho = echo;
		this.rightTrig = trig;
		break;
	case this.middle:
		// [en] @todo requires servo control to move eye side to side
		// [es] @todo (para hacer) requiere control de servo para mover el ojo de lado a lado
		this.middleEcho = echo;
		this.middleTrig = trig;
		break;
	}
	pinMode(echo, INPUT);
	pinMode(trig, OUTPUT);
};

int Eyeslib::distance(int eye)
{
	switch (eye)
	{
	case this.left:
		return distance(this.leftEcho, this.leftTrig);
	case this.right:
		return distance(this.rightEcho, this.rightTrig);
	case this.middle:
		// [en] @todo requires servo control to move eye side to side
		// [es] @todo (para hacer) requiere control de servo para mover el ojo de lado a lado
		return this._distance(this.middleEcho, this.middleTrig);
	}
};