#include<iostream>
using namespace std;

class Animal{ // Base Class
    public:
    void eat(){
        cout<<"This animal eats food"<<endl;
    }
};

class Dog: public Animal { // Derived Class
    public:
    void bark(){
        cout<<"Dog Barks"<<endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat(); // inherited from animal
    myDog.bark(); // Defined in dog

    return 0;
}