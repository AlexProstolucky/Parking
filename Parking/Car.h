#pragma once
#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
	string model;
public:
	int x;
	int y;
	Car(string _model);
	Car();
	string GetModel();
	void Print();
	void SetModel(string _model);
	int set_out();
	void info_out();
};

