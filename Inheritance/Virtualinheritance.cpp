#include<iostream>
using namespace std;

class Animal{

    public:
    void eat(){
        cout<<"This animal eats"<<endl;
    }

};

class Mammal: virtual public Animal{}; //Inherits Animal
class Bird: virtual public Animal{}; //Inherits Animal

class Bat: public Mammal, public Bird{}; //Inherits mammal and bird both, inherits Animal from both

int main() {
    Bat bat;
    bat.eat(); // ✅ No ambiguity, only one copy of Animal
    return 0;
}