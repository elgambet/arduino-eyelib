/*
  Drivelib.h - Library for controlling elegoo smart robot car v1.0
  Created by Pablo Gambetta December 2016
  Released into the public domain.
*/
#ifndef Eyeslib_h
#define Eyeslib_h

#include "Arduino.h"

class Eyeslib
{
public:
	void setEye(int echo, int trig, int eye);
	int distance(int eye);
	int middle;
	int middleEcho;
	int middleTrig;
	int left;
	int leftEcho;
	int leftTrig;
	int right;
	int rightEcho;
	int rightTrig;
};

#endif