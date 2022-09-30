#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include "Car.h"
#include "Bus.h"
#include "Truck.h"
using namespace std;

unsigned short int max_car = 15, max_bus = 10, max_truck = 5;
const double max_weight = 15;
string path = "Data_base.txt";

random_device random_devic;
mt19937 generator(random_devic());
uniform_int_distribution<> x(1, 100);
uniform_int_distribution<> y(1, 100);

class Parking
{
private:
    vector <Car> car;
    vector <Bus> bus;
    vector <Truck> trucks;
public:
    void add(Car _car)
    {
        if (car.size() < max_car) {
            car.push_back(_car);
            cout << "\nCar added";
        }
        else {
            cout << "\nThe parking lot is busy!";
        }
    }
    void add(Bus _bus)
    {
        if (bus.size() < max_bus) {
            bus.push_back(_bus);
            cout << "\nBus added";
        }
        else {
            cout << "\nThe parking lot is busy!";
        }
    }
    void add(Truck _truck)
    {
        if (trucks.size() < max_truck && _truck.getWeight() < max_weight) {
            trucks.push_back(_truck);
            cout << "\nTruck added";
        }
        else {
            cout << "\nThe parking lot is busy or your truck too heavy!";
        }
    }

    void addCar(string model)
    {
        if (car.size() < max_car) {
            Car buff;
            buff.SetModel(model);
            car.push_back(buff);
            cout << "\nCar added";
            cout << "\nModel: " << model << endl;
        }
        else {
            cout << "\nThe parking lot is busy!";
        }
    }

    void addBus(string model, int seats)
    {
        if (bus.size() < max_bus) {
            Bus buff;
            buff.Set(model, seats);
            bus.push_back(buff);
            cout << "\nBus added:" << endl;
            cout << "Model: " << model << endl;
            cout << "Seats: " << seats << endl;
        }
        else {
            cout << "\nThe parking lot is busy!";
        }
    }

    void addTruck(string model, int weight)
    {
        if (trucks.size() < max_truck && weight < max_weight) {
            Truck buff;
            buff.Set(model, weight);
            trucks.push_back(buff);
            cout << "\nTruck added:";
            cout << "\nModel: " << model << endl;
            cout << "Weight: " << weight << endl;
        }
        else {
            cout << "\nThe parking lot is busy or your truck too heavy!";
        }
    }

    void removeC(unsigned short int number)
    {
        if (number < car.size()) {
            car.erase(car.begin() + number);
            cout << "\nThe car left the parking lot";
        }
        else {
            cout << "\nError, the number is the bigest than the number of cars";
            cout << "\nInput new number --> ";
            cin >> number;
            removeC(number);
        }
    }

    void removeB(unsigned short int number)
    {
        if (number < bus.size()) {
            bus.erase(bus.begin() + number);
            cout << "\nThe bus left the parking lot";
        }
        else {
            cout << "\nError, the number is the bigest than the number of cars";
            cout << "\nInput new number --> ";
            cin >> number;
            removeB(number);
        }
    }

    void removeT(unsigned short int number)
    {
        if (number < trucks.size()) {
            trucks.erase(trucks.begin() + number);
            cout << "\nThe truck left the parking lot";
        }
        else {
            cout << "\nError, the number of car is less than the number you entered for remove car";
            cout << "\nInput new number --> ";
            cin >> number;
            removeT(number);
        }
    }

    void outCar(unsigned short int number)
    {
        car[number].x = x(generator);
        car[number].y = y(generator);
        car[number].info_out();
    }

    void outBus(unsigned short int number)
    {
        bus[number].x = x(generator);
        bus[number].y = y(generator);
        bus[number].info_out();
    }

    void outTruck(unsigned short int number)
    {
        trucks[number].x = x(generator);
        trucks[number].y = y(generator);
        trucks[number].info_out();
    }

    void info()
    {
        infocar();
        infobus();
        infotruck();
    }
    void infocar()
    {
        cout << endl;
        if (car.size() > 0) {
            cout << "INFO ABOUT CAR(S)" << endl;
            for (int i = 0; i < car.size(); i++)
            {
                Car buff = car[i];
                cout << "\nCar:";
                cout << "\nModel: " << buff.GetModel() << endl;
            }
        }
        else cout << "There are no cars in the parking lot" << endl;
    }

    void infobus()
    {
        cout << endl;
        if (bus.size() > 0) {
            cout << "INFO ABOUT BUS(ES)" << endl;
            for (int i = 0; i < bus.size(); i++)
            {
                Bus buff = bus[i];
                cout << "\nBus:";
                cout << "\nModel: " << buff.getModel() << endl;
                cout << "Seats: " << buff.getSeats() << endl;
            }
        }
        else cout << "There are no buses in the parking lot" << endl;
    }

    void infotruck()
    {
        cout << endl;
        if (trucks.size() > 0) {
            cout << "INFO ABOUT TRUCK(S)" << endl;
            for (int i = 0; i < trucks.size(); i++)
            {
                Truck buff = trucks[i];
                cout << "\nTruck:";
                cout << "\nModel: " << buff.getModel() << endl;
                cout << "Weight: " << buff.getWeight() << endl;
            }
        }
        else cout << "There are no trucks in the parking lot" << endl;
    }

    void inData()
    {
        ofstream file;
        file.open(path);
        string str;
        if (file.is_open()) {
            for (size_t i = 0; i < car.size(); i++)
            {
                Car buff = car[i];
                str = buff.GetModel();
                file << str << " ";
            }
            file << "\n";
            for (size_t i = 0; i < bus.size(); i++)
            {
                Bus buff = bus[i];
                str = buff.getModel();
                file << str << ".";
                str = buff.getSeats();
                file << str << " ";
            }
            file << "\n";
            for (size_t i = 0; i < trucks.size(); i++)
            {
                Truck buff = trucks[i];
                str = buff.getModel();
                file << str << ".";
                str = to_string(buff.getWeight());
                file << str << " ";
            }
            file.close();
        }
        else cout << "Error! File could not be opened";
    }
    int i = 0;
    int count = 1;
    void outData()
    {
        cout << "The program reads the database:";
        fstream file;
        file.open(path, fstream::in | fstream::app | fstream::out);
        string str;
        if (file.is_open()) 
        {
            while (!file.eof()) 
            {
                getline(file, str);
                size_t last_pos = 0;
                size_t pos = 0;
                string model;
                int seats;
                double weight;
                switch (i) 
                {
                case 0:
                    while (str.find(' ', pos + 1) != str.npos)
                    {
                        string model;
                        pos = str.find(' ', pos + 1);
                        model = str.substr(last_pos, pos - last_pos);
                        last_pos = pos + 1;
                        addCar(model);
                    }
                    i++;
                    continue;
                case 1:
                    while (str.find(' ', pos + 1) != str.npos)
                    {
                        if (count % 2 != 0)
                        {
                            pos = str.find('.', pos + 1);
                            model = str.substr(last_pos, pos - last_pos);
                            last_pos = pos + 1;
                            count++;
                            continue;
                        }
                        else
                        {
                            pos = str.find(' ', pos + 1);
                            seats = stoi(str.substr(last_pos, pos - last_pos));
                            last_pos = pos + 1;
                            count++;
                        }
                        addBus(model, seats);
                    }
                    i++;
                    continue;
                case 2:
                    while (str.find(' ', pos + 1) != str.npos)
                    {
                        if (count % 2 != 0)
                        {
                            pos = str.find('.', pos + 1);
                            model = str.substr(last_pos, pos - last_pos);
                            last_pos = pos + 1;
                            count++;
                            continue;
                        }
                        else
                        {
                            pos = str.find(' ', pos + 1);
                            weight = (double)stoi(str.substr(last_pos, pos - last_pos));
                            last_pos = pos + 1;
                            count++;
                        }
                        addTruck(model, weight);
                    }
                    break;
                }
            }
        }
        else cout << "Error open";
        cout << "\nAll data is loaded" << endl;
        file.close();
    }
};


int main()
{
    Parking parking;
    parking.outData();
    parking.outCar(0);
    parking.outCar(1);

    parking.inData();
}