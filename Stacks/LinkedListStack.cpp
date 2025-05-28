#include<iostream>
using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Stack{

    private:
    Node* top;

    public:
    Stack(){
        top = nullptr;
    }

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop(){
        if(top == nullptr){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    int peek(){
        return (top != nullptr) ? top->data:-1;
    }

    bool isEmpty(){
        return (top == nullptr);
    }

    void display(){
        if(top == nullptr){
            cout<<"Stack is empty!"<<endl;
            return;
        }

        Node* temp = top;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(15);
    s.push(25);

    s.display();  // Output: 25 15 5

    cout << "Top Element: " << s.peek() << endl; // Output: 25

    s.pop();
    s.display();  // Output: 15 5

    return 0;
}