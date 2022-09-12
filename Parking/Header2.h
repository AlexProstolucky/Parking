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
