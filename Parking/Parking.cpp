#include <iostream>
#include <vector>
using namespace std;

unsigned short int max_car = 15, max_bus = 10, max_truck = 5;
const double max_weight = 6.5;
class Car
{
private:
    string model;
public:

    Car(string _model) :model(_model)
    {
    }
    Car() : Car("")
    {
    }
    string GetModel() { return model; }
    void SetModel(string _model)
    {
        this->model = _model;
    }
    void Print()
    {
        cout << "Модель: " << model << endl;
    }
};

class Bus
{
private:
    string model;
    unsigned int seats;
public:
    Bus(string _model, int _seats) : model(_model), seats(_seats)
    {
    }
    Bus() : Bus("", 0) {}
    void Set(string _model, int _seats)
    {
        this->model = _model;
        this->seats = _seats;
    }
    void Print()
    {
        cout << "Модель: " << model << ", сидінь: " << seats << endl;
    }
};

class Truck
{
private:
    string model;
    double weight;
public:
    Truck(string _model, double _weight) : model(_model), weight(_weight)
    {
    }
    Truck() : Truck("", 0) {}

    void Set(string _model, double _weight)
    {
        this->model = _model;
        this->weight = _weight;
    }
    double getWeight()
    {
        return this->weight;
    }
    void Print()
    {
        cout << "Модель: " << model << ", вага: " << weight << endl;
    }
};
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
            cout << "\nBus added";
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
            cout << "\nTruck added";
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
            cout << "\nError, the number is the bigest than the number of cars"; 
            cout << "\nInput new number --> ";
            cin >> number;
            removeT(number);
        }
    }

    void info() 
    {
        cout << "\nCar(s) on parking --> " << car.size();
        cout << "\nBus(es) on parking --> " << bus.size();
        cout << "\nTruck(s) on parking --> " << trucks.size();
    }
};

int main()
{
    Parking parking;
    Car a("BMW");
    Bus b("Bogdan", 30);
    Truck c("Mersedes", 6);
    parking.add(a);
    parking.add(b);
    parking.add(c);
    parking.addCar("Tesla");
    parking.removeC(10);
    parking.info();
}