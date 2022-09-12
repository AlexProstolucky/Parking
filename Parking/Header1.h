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
