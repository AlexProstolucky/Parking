#pragma once
#include <iostream>
#include <string>
using namespace std;
class Truck
{
private:
    string model;
    double weight;
public:
    Truck(string _model, double _weight);
    Truck();
    void Set(string _model, double _weight);
    double getWeight();
    string getModel();
    void Print();
};

