#include<iostream>
using namespace std;

class Queue{

    private:
    int* arr;
    int front, rear, capacity;

    public:
    Queue(int size){
        arr = new int[size];
        capacity = size;
        front = rear = -1;
    }

    void enqueue(int x){
        if(rear == capacity - 1){ 
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(front == -1) front = 0; // set a front 

        arr[++rear] = x;
    }

    void dequeue(){
        if(front == -1 || front>rear){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        cout<<"Removed: "<<arr[front++];
    }

    void display(){
        if(front == -1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i=front; i<= rear; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    ~Queue(){ delete[] arr; }
};