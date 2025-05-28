#include<iostream>
using namespace std;

//A void* is a generic pointer — it can point to any type of data, but it doesn’t know what type it's pointing to.

void printValue(void* data, char type) {
    if (type == 'i') {
        cout << "Int: " << *(int*)data << endl;
    } else if (type == 'f') {
        cout << "Float: " << *(float*)data << endl;
    }
}

int main() {
    int a = 42;
    float b = 3.14;

    printValue(&a, 'i'); // output: Int: 42
    printValue(&b, 'f'); // output: Float: 3.14

    return 0;
}