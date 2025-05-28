#include<iostream>
using namespace std;

template<typename T>
T sumAll(T value){
    return value;
}

template<typename T, typename...Args>
T sumAll(T first, Args...rest){
    return first + sumAll(rest...);
}

int main(){
    cout<<sumAll(100)<<" "<<
    sumAll(1,2,3)<<" "<<
    sumAll(1.1,2.2)<<" "<<
    sumAll(20,10,30)<<" "<<
    sumAll(10,10,10,10,10);

    return 0;
}