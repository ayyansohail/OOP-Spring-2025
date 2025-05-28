#include<iostream>
using namespace std;

class CircularQueue{

    private:
    int* arr;
    int front, rear, capacity;

    public:
    CircularQueue(int size){
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    void enqueue(int x){
        if((rear + 1) % capacity == front){ //empty queue
            cout<<"Queue Overflow. Cannot insert"<< endl;
            return;
        }
        if(front == -1) front = 0; 
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        cout<<"Inserted Value: "<<x<<endl;
    }

    void dequeue(){
        if(front == -1){
            cout<<"Queue Underflow. Nothing to delete"<<endl;
            return;
        }
        cout<<"Removed Value: "<<arr[front]<<endl;
        if(front == rear){
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    void display(){
        int i = front;
        while(true){
            cout<<arr[i]<<" ";
            if(i == rear){
                break;
            }
            i = (i+1) % capacity;
        }
        cout<<endl;
    }

    ~CircularQueue(){ delete[] arr; }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);  // Queue full
    cq.display();

    cq.dequeue();
    cq.dequeue();
    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    return 0;
}