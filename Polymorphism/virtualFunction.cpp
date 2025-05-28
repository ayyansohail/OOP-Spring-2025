#include<iostream>
using namespace std;

class Base{
    public:
    virtual void show(){ // virtual function
        cout<<"Base Class show() function\n";
    }
};

class Derived: public Base{
    public:
    void show() override {// overriding function
        cout<<"Derived Class show() function\n";   
    }
};

int main(){
    Base* ptr;
    Derived obj;
    ptr = &obj;

    ptr->show(); //Calls derived class show() function (Late Binding)

    return 0;
}