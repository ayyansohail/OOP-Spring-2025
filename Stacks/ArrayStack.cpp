#include<iostream>
using namespace std;

class Stack {

    private:
    int *arr;
    int top;
    int capacity;

    public:
    Stack(int size){
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int x){
        if(top == capacity - 1){ // Stack is full
            cout<<"Stack Overflow"<<endl;
            return;
        }

        arr[++top] = x; //pre increment top eg from -1 to and add value to arr[0]
    }

    int pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }

        return arr[top--]; // Shows the popped value and decreases the top after that
    }

    int peek(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    void display(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }

        for(int i=top; i>=0 ; i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }

    ~Stack(){ delete[] arr;}
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    
    s.display();  // Output: 30 20 10

    cout << "Top Element: " << s.peek() << endl; // Output: 30
    
    s.pop();
    s.display();  // Output: 20 10

    return 0;
}