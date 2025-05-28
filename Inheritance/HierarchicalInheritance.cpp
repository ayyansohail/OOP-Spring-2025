#include<iostream>
using namespace std;
// Muiltiple derived classes from one base class
class Animal {
    public:
        void eat() {
            cout << "This animal eats food." << endl;
        }
    };
    
    class Dog : public Animal {
    public:
        void bark() {
            cout << "Dog barks." << endl;
        }
    };
    
    class Cat : public Animal {
    public:
        void meow() {
            cout << "Cat meows." << endl;
        }
    };
    
    int main() {
        Dog myDog;
        Cat myCat;
    
        myDog.eat(); // Inherited from Animal
        myDog.bark();
    
        myCat.eat(); // Inherited from Animal
        myCat.meow();
    
        return 0;
    }