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

int Truck::set_out()
{
	return sqrt(pow((this->x - 0), 2.0) + pow((this->y - 0), 2.0));
}

void Truck::info_out()
{
	int dis = set_out();
	if (dis > 0)
		cout << "The distance between the station and the truck, models - " << model << " with the carrying capacity - " << weight << " this is (" << dis << ")!\n";
	else cout << "Transportation in the parking!" << endl;
}
