#include<iostream>
using namespace std;

template <typename T>
T add (T a, T b){
    return a + b;
}

int main() {
    cout<<add<int>(3,4)<<endl;
    cout<<add<double>(1.1,2.2)<<endl;
    cout<<add<string>("Ayyan ", "Khanani")<<endl;

    return 0;
}