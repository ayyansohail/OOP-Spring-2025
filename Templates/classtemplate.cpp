#include <iostream>
using namespace std;

template <class T>

class Box {
    private:
    T value;

    public:
    void set(T val){
        value = val;
    }
    
    T get() {
        return value;
    }
};

int main() {
    Box<int> intBox;
    intBox.set(100);
    cout<<intBox.get()<<endl;

    Box<string> strBox;
    strBox.set("Ayyan Khanani");
    cout<<strBox.get()<<endl;

    return 0;
}