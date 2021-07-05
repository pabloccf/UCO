#include <iostream>
#include <string>
using namespace std;

class Motor{
    private:
      string name_;
    public:
      void setName(string name){name_=name;}
      string getName(){return name_;}
      virtual void start()=0;
};

class DieselEngine: public Motor{
    public:
      DieselEngine(){setName("Diesel Engine");} //and calls to disel stuff
      void start(){cout << "start Diesel Engine\n";}
};

class BoxerEngine: public Motor{
    public:
      BoxerEngine(){setName("Boxer Engine");} //and calls to boxer stuff
      void start(){cout << "start Boxer Engine\n";}
};

class Vehicle
{
    public:
      string name; // just to avoid get/set in this example
      Vehicle(){}
      /* This is the factory method. */
      static Vehicle* getVehicle(string name);
      virtual Motor* getMotor()=0;
};

class Car: public Vehicle
{
    public:
      Car(){name = "Car";}
      Motor* getMotor(){return &de_;}
    private:
      DieselEngine de_;
};

class Motorbike: public Vehicle
{
    public:
      Motorbike(){name = "Motorbike";}
      Motor* getMotor(){return &be_;}
    private:
      BoxerEngine be_;
};

/* This is the static factory method */
Vehicle* Vehicle::getVehicle(string name)
{
    if (name == "Car")
        return new Car();
    else if (name == "Motorbike")
        return new Motorbike();
    else
        return 0;
}

/* A little testing */
int main()
{
    /* Now we decide the type of the Vehicle at
     * runtime by the factory method argument */
    Vehicle* car  = Vehicle::getVehicle("Car");
    cout << car->name << std::endl;
    car->getMotor()->start();

    Vehicle* motorbike = Vehicle::getVehicle("Motorbike");
    cout << motorbike->name << std::endl;
    motorbike->getMotor()->start();
}
