#include<iostream>
using namespace std;

class Deque{

    private:
    int* arr;
    int front, rear, capacity, size;

    public:
    Deque(int c){
        capacity = c;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

    void insertFront(int x){
        if(isFull()){
            cout<<"Queue is full!"<<endl;
            return;
        }
        if(isEmpty()){
            front = rear = 0;
        } else {
            front = (front + 1) % capacity;
        }
        cout<<"Inserted at front: "<<x<<endl;
        arr[front] = x;
        size++;

    }

    void insertRear(int x){
        if(isFull()){
            cout<<"Queue is full!"<<endl;
            return;
        }
        if(isEmpty()){
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        size++;
        cout<<"Inserted at rear: "<<endl;
    }

    void deleteFront(){
        if(isEmpty()){
            cout<<"Queue is empty. Nothing to delete"<<endl;
            return;
        }
        cout<<"Deleted from front: "<<arr[front]<<endl;
        if(front == rear){
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    void deleteRear(){
        if(isEmpty()){
            cout<<"Queue is empty. Nothing to delete."<<endl;
            return;
        }
        cout<<"Removed from rear: "<<arr[rear]<<endl;
        if(front == rear){
            front = rear = -1;
        } else {
            rear = (rear + 1) % capacity;
        }
        size--;
    }

    int getFront(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        return arr[front];
    }

    int getRear(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        return arr[rear];
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }

        int i = front;
        while(true){
            cout<<arr[i]<<" ";
            if(i == rear) break;
            rear = (rear + 1) % capacity;
        }
        cout<<endl;

    }

~Deque(){
    delete[] arr;
}
};