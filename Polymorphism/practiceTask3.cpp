#include<iostream>
using namespace std;

/*
Design a class hierarchy to model different types of vehicles with behaviors like honking, speed tracking, and fuel consumption.

1. Base Class: Vehicle
Attributes:

brand (string)
speed (int, km/h)
fuelCapacity (float, liters)
Methods:

virtual void honk() → Default honk "Generic vehicle honk!"
virtual void displayInfo() → Prints brand, speed, and fuel capacity.
2. Derived Classes
Car (inherits Vehicle):

Overrides honk() → "Car horn: Beep Beep!"
Adds numSeats (int) attribute.
Overrides displayInfo() → Prints car-specific details.
Motorcycle (inherits Vehicle):

Overrides honk() → "Motorcycle horn: Meep Meep!"
Adds hasSideCar (bool) attribute.
Overrides displayInfo() → Displays sidecar info.
Truck (inherits Vehicle):

Overrides honk() → "Truck horn: HOOOONK!"
Adds cargoCapacity (float, tons).
Overrides displayInfo() → Displays cargo capacity.
*/

class Vehicle{

    protected:
    string brand;
    int speed;
    float fuelCapacity;

    public:
    Vehicle(string b, int s, float f): brand(b), speed(s), fuelCapacity(f) {}

    virtual void honk(){
        cout<<"Generic Vehicle honk\n";
    }

    virtual void displayInfo(){
        cout<<"Brand: "<<brand<<" | Speed: "<<speed<<" | Fuel Capacity: "<<fuelCapacity<<endl;
    }
};

class Car: public Vehicle{
    private:
    int numSeats;

    public:
    Car(string name, int speed, float fuelCapacity, int n): Vehicle(name,speed,fuelCapacity), numSeats(n) {}

    void honk() override {
        cout<<"Car horns: Beep Beep\n";
    }

    void displayInfo() override{
        cout<<"Car Brand: "<<brand<<" | Speed: "<<speed<<" | Fuel Capacity: "<<fuelCapacity<<" | Number of seats: "<<numSeats<<endl;
    }
};

class Motorcycle: public Vehicle{
    private:
    bool hasSideCar;

    public:
    Motorcycle(string name, int speed, float fuelCapacity, bool sidecar): Vehicle(name, speed, fuelCapacity), hasSideCar(sidecar) {}

    void honk() override{
        cout<<"Motorcycle honks: Meep Meep\n";
    }

    void displayInfo() override{
        cout<<"Brand: "<<brand<<" | Speed: "<<speed<<" | Fuel Capacity: "<<fuelCapacity<<endl;
        if(hasSideCar){
            cout<<"Has a side car\n";
        } else {
            cout<<"Does not have a side car";
        }
    }
};

int main(){

    Car myCar("Toyota",120, 50.0, 4);
    Motorcycle myBike("Yamaha", 100, 20.5, 0);
    myCar.honk();
    myCar.displayInfo();
    myBike.honk();
    myBike.displayInfo();

    return 0;
}