#include<iostream>
using namespace std;

void testExceptions(int num){
    try {
        if(num == 0){
            throw "Zero not allowed"; // will show this error when input is zero
        }
        if(num<0) throw num;
        cout<<"Valid number: "<<num<<endl; // will show this error when integer is -ve
    }
    catch(const char* message){
        cout<<"Caught String exception: "<<message<<endl; //for zero exception
    }
    catch(int value){
        cout<<"Caught integer exception: Negative number: "<<num<<endl; // for -ve exception
    }
}

/*
✔ Multiple catch blocks handle different exception types.
✔ throw "Zero is not allowed!" → Caught by catch (const char*).
✔ throw num; (negative value) → Caught by catch (int).
*/

int main() {
    testExceptions(5); // Output Valid
    testExceptions(0); // Zero exception
    testExceptions(-3); // -ve exception

    return 0;
}