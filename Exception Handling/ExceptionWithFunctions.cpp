#include<iostream>
using namespace std;

double divide(int a, int b){
    if(b == 0){
        throw "Cannot divide by zero";
    }
    return a/b;
}

int main() {
    try{
        cout<<"Result: "<<divide(10,2)<<endl;
        cout<<"Result: "<<divide(8,0)<<endl; // This will throw an exception
    }
    catch(const char* error){
        cout<<"Exception caught: "<<error<<endl;
    }

    return 0;
}