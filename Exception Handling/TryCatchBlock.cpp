#include<iostream>
using namespace std;

int main() {
    try {
        cout<<"Trying to divide by zero....."<<endl;
        throw "Error: Division by zero"; // throw an exception
    } catch(const char* message){ // catch block handles the exception
        cout<<"Exception caught: "<<message<<endl;
    }
    cout<<"Program continues normally..."<<endl;
    return 0;
}