#include<iostream>
using namespace std;

//✔ Memory is properly freed when using virtual destructors!

class Base {

    public:
    virtual ~Base() { cout<<"Base Class Destructor\n"; }
};

class Derived: public Base {

    public:
    ~Derived(){ cout<<"Derived Class Destructor\n"; }
};

int main(){
    Base* ptr = new Derived();
    delete ptr; // Calls both destructors

    return 0;
}