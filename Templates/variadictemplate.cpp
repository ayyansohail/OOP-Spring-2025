#include<iostream>
using namespace std;

template<typename T>
void printAll(T value) {
    cout<<value<<endl;
}

template<typename T, typename ... Args>
void printAll(T first, Args ... rest){
    cout<<first<<endl;
    printAll(rest...);
}

int main(){
    printAll<int>(1);
    printAll<string>("Ayyan Khanani");
    printAll(1,2.5,'H',"ello");
}