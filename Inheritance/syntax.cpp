#include<iostream>
using namespace std;

class Parent{
    //Base class
};

class Child : public Parent { // public is an access specifier, it could be public. private or protected
    //Derived Class           // if no specifier mentioned, private by default
};