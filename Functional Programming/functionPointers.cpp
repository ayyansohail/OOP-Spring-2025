#include <iostream>
using namespace std;
//Basic Function Pointers
void greet() {
    cout<<"Hello from a function"<<endl;
}

int main() {
    void(*funcPtr)() = greet; //Function Pointer
    funcPtr();

    return 0;
}