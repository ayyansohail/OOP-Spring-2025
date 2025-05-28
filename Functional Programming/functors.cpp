#include<iostream>
using namespace std;

// A functor is any class that overloads the operator() so it can be used like a function.

class Multiply {

    public:
    int operator()(int a, int b){
        return a*b;
    }
};

int main() {
    Multiply mul;
    cout << mul(3,4) << endl;

    return 0;
}