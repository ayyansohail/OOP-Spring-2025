#include<iostream>
using namespace std;

void testUnknownExceptions(int num){
    try{
        if (num == 0) throw "Zero is not allowed!";
        if (num < 0) throw num;
        throw 2.5; // Throws a double (no specific catch)
    }
    catch (const char* message) {
        cout << "Caught String Exception: " << message << endl;
    }
    catch (int value) {
        cout << "Caught Integer Exception: Negative Number: " << value << endl;
    }
    catch(...) {
        cout<<"Caught an unknown exception"<<endl;
    }
}

int main() {
    testUnknownExceptions(5);
    testUnknownExceptions(0);
    testUnknownExceptions(-1);

    return 0;
}