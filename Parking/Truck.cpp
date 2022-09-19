#include "Truck.h"

Truck::Truck(string _model, double _weight) : model(_model), weight(_weight)
{
}

Truck::Truck() : Truck("", 0)
{
}

void Truck::Set(string _model, double _weight)
{
	this->model = _model;
	this->weight = _weight;
}

double Truck::getWeight()
{
	return this->weight;
}

string Truck::getModel()
{
	return this->model;
}

void Truck::Print()
{
	cout << "Модель: " << model << ", вага: " << weight << endl;
}
