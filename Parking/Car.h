#pragma once
#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
	string model;
public:
	Car(string _model);
	Car();
	string GetModel();
	void Print();
	void SetModel(string _model);
};

