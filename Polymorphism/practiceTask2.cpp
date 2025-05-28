#include<iostream>
using namespace std;

/*
📌 Problem Statement
Create a base class Shape with a virtual function area().
Then, create two derived classes:

Rectangle → area() should return length × width.
Circle → area() should return π × radius².
✅ Use base class pointers to calculate the areas dynamically.
*/

class Shape{
    public:
    virtual double area(){
        cout<<"Every shape has an area"<<endl;
        return 0;
    }
};

class Rectangle: public Shape{
    private:
    double length;
    double width;

    public:
    Rectangle(double l, double w){
        length = l;
        width = w;
    }

    double area() override{
        return length*width;
    }
};

class Circle: public Shape{
    private:
    double radius;

    public:
    Circle(double r){
        radius = r;
    }

    double area() override {
        return 3.14159*radius*radius;
    }
};

int main(){

    Shape* s1 = new Rectangle(2,4);
    Shape* s2 = new Circle(7);

    cout<<"Area of Recatngle: "<<s1->area()<<endl;
    cout<<"Area of Circle: "<<s2->area()<<endl;

    delete s1;
    delete s2;

    return 0;
}