#pragma once
#include <iostream>
#include <string>
using namespace std;
class Bus
{
private:
    string model;
    unsigned int seats;
public:
    int x;
    int y;
    Bus(string _model, int _seats);
    Bus();
    void Set(string _model, int _seats);
    void Print();
    string getModel();
    string getSeats();
    int set_out();
    void info_out();
};

