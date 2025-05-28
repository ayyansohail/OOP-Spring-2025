#include<iostream>
using namespace std;

class Animal{

    public:

    void eat(){
        cout<<"This animal eats."<<endl;
    }

};

class Pet{

    public:

    void play(){
        cout<<"This pet loves to play"<<endl;
    }

};

class Dog: public Animal, public Pet { // Inherits multiple Base Classes

    public:

    void bark(){
        cout<<"Dog Barks!"<<endl;
    }

};

int main(){
    Dog d1;
    d1.eat(); // inherited from Animal
    d1.play(); // Inherited from Pet
    d1.bark();

    return 0;
}