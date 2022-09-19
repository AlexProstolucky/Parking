#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Bus.h"
#include "Car.h"
#include "Truck.h"
#include "Point.h"

int distance(Point point1, Point point2);

class GPS
{
private:
	vector <Car> removedC;
	vector <Bus> removedB;
	vector <Truck> removedT;
	string coordinates;
	string parking_crdin = "50.170.30";
public:
	void getC(string model);
	void getB(string model, int seats);
	void getT(string model, double weight);
};


