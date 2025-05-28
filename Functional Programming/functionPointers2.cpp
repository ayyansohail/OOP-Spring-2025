#include<iostream>
using namespace std;

//Function Pointer with Parameters
int add(int a, int b) {
    return a+b;
}

int main() {
    int(*op)(int,int) = add;
    cout<<op(3,4)<<endl; //returns 7

    return 0;
}