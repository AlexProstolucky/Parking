#include "GPS.h"

int distance(Point point1, Point point2)
{
	return sqrt(pow((point2.getX() - point1.getX()), 2) + pow(point2.getY() - point1.getY(), 2) + pow(point2.getZ() - point1.getZ(), 2));
}

void GPS::getC(string model)
{
	int counter;
	Car buff(model);
	removedC.push_back(buff);
	cout << "The car model: " << model << " added to GPS list" << endl;
	cout << "Please input coordinates, fomat(50.170.30)";
}
