#include<iostream>
#include<vector>
using namespace std;

//Generate all binary strings of length n, e.g., for n = 3: 000, 001, 010, 011, 100, 101, 110, 111

void generateBinary(int n, string current){
    if(current.length() == n){
        cout<<current<<endl;
        return;
    }

    //Try 0
    generateBinary(n, current + "0");

    //Try 1
    generateBinary(n, current + "1");
}

int main(){
    int n = 3;
    generateBinary(n, "");
    return 0;
}