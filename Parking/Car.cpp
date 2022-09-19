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
