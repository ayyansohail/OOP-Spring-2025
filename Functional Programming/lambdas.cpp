#include<iostream>
using namespace std;

// Syntax: [capture](parameters) -> return_type { body }

int main() {
    auto sum = [](int a, int b) {
        return a+b;
    };
    cout<<sum(5,7);

    //Capturing Parameters
    int x = 10; int y = 5;
    auto print = [x, &y]() {
        cout<<x<<" "<<y<<endl;
    };

    print();

    return 0;
}

