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
