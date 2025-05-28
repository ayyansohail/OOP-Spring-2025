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

class Queue{

    private:
    Node* front;
    Node* rear;

    public:
    Queue(){
        front =  nullptr;
        rear = nullptr;
    }

    void enqueue(int x){
        Node* newNode = new Node(x);
        if(rear == nullptr){
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue(){
        if(front == nullptr){
            cout<<"Queue Underflow"<<endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if(front == nullptr) rear = nullptr;
    }

    void display(){
        Node* temp = front;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30

    q.dequeue();
    q.display();  // Output: 20 30

    return 0;
}