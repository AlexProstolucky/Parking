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