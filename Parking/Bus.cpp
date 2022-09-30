#include "Bus.h"

Bus::Bus(string _model, int _seats) : model(_model), seats(_seats)
{
}

Bus::Bus() : Bus("", 0)
{
}

void Bus::Set(string _model, int _seats)
{
	this->model = _model;
	this->seats = _seats;
}

void Bus::Print()
{
	cout << "Модель: " << model << ", сидінь: " << seats << endl;
}

string Bus::getModel()
{
	return model;
}

string Bus::getSeats()
{
	return to_string(seats);
}

int Bus::set_out()
{
	return sqrt(pow((this->x - 0), 2.0) + pow((this->y - 0), 2.0));
}

void Bus::info_out()
{
	int dis = set_out();
	if(dis > 0)
		cout << "The distance between the station and the bus, models - " << model << " with the number of seats - " << seats << " this is (" << dis << ")!\n";
	else cout << "Transportation in the parking!" << endl;
}
