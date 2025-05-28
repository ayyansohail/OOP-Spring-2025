#include<iostream>
using namespace std;

class Animal{

    public:

    void eat(){
        cout<<"This animal eats."<<endl;
    }

};

class Mammal: public Animal{ // Inherits from Animal Class

    public:

    void birth(){
        cout<<"Nigga seggs"<<endl;
    }

};

class Dog : public Mammal { // Inherits from Mammal(already a derived class)
    public:
        void bark() {
            cout << "Dog barks." << endl;
        }
    };
    
    int main() {
        Dog myDog;
        myDog.eat();       // Inherited from Animal
        myDog.birth(); // Inherited from Mammal
        myDog.bark();      // Defined in Dog
        return 0;
    }
    
