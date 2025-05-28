#include<iostream>
using namespace std;

class DynamicArray{

    private:
    int* arr;
    int capacity;
    int size;

    void resize(int newCapacity){
        int* temp = new int[newCapacity]; //Allocate a new larger array
        for(int i=0; i<size; i++){
            temp[i] = arr[i]; //copying old elements
        }

        delete[] arr; // free old memory
        arr = temp;
        capacity = newCapacity;
    }

    public:
    DynamicArray(int initialSize){
        capacity = initialSize;
        size = 0;
        arr = new int[capacity];
    }

    void push_back(int value){
        if(size == capacity){
            resize(capacity*2); // double initial capacity
        }

        arr[size++] = value;
    }

    void pop_back(){
        if(size > 0){
            size--;
            if(size< capacity/4 && capacity>4){
                resize(capacity/2); // reduce size when 25% filled
            }
        }
    }

    int get(int index){
        if(index<0 || index>= size){
            cout<<"Out of bounds"<<endl;
            return -1;
        }
        return arr[index];
    }

    void set(int index, int value){
        if(index<0 || index>=size){
            cout<<"Out of bounds"<<endl;
            return;
        }
        arr[index] = value;
    }

    void display(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    ~DynamicArray(){ delete[] arr; }
};

int main() {
    DynamicArray arr(4);
    
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.display();  // Output: 10 20 30 40

    arr.push_back(50);  // Triggers resize
    arr.display();  // Output: 10 20 30 40 50

    arr.pop_back();
    arr.display();  // Output: 10 20 30 40

    return 0;
}