#include<iostream>
using namespace std;

/*
📌 Problem Statement
Create a base class Animal with a virtual function makeSound().
Then, create two derived classes:

Dog → makeSound() should print "Dog barks".
Cat → makeSound() should print "Cat meows".
✅ Use a base class pointer to call the overridden functions.
*/

class Animal{

    public:
    virtual void makeSound(){
        cout<<"This animal makes a sound: ";
    }
};

class Dog: public Animal{

    public:
    void makeSound() override{
        cout<<"Barks\n";
    }
};

class Cat: public Animal{

    public:
    void makeSound() override{
        cout<<"Meows\n";
    }
};

int main(){
    Animal* ptr1;
    Animal* ptr2;
    Dog d1;
    Cat c1;
    ptr1 = &d1;
    ptr2 = &c1;

    ptr1->makeSound();
    ptr2->makeSound();

    return 0;
}