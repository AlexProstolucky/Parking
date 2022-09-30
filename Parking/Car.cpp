#include "Car.h"

Car::Car(string _model) :model(_model)
{
}

Car::Car() : Car("")
{
}

string Car::GetModel()
{
	return model;
}

void Car::Print()
{
	cout << "Модель: " << model << endl;
}

void Car::SetModel(string _model)
{
	this->model = _model;
}

int Car::set_out()
{
	return sqrt(pow((this->x - 0), 2.0) + pow((this->y - 0), 2.0));
}

void Car::info_out()
{
	int dis = set_out();
	if (dis > 0)
		cout << "The distance between the station and the auto, models - " << model << " this is (" << dis << ")!\n";
	else 
		cout << "Transportation in the parking!" << endl;
}
