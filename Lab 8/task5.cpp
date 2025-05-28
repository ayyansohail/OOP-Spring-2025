#include<iostream>
using namespace std;

int findpos( void* A, int n, int (*fp)(void* A, int n)){
    return fp(A,n);
}

int fpMaxInt(void* A, int n){
    int* arr = (int*)A;
    int maxIndex = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > arr[maxIndex]){
            maxIndex = i;
        }
    }
    return maxIndex;
}

int fpMinFloat(void* A, int n){
    float* arr = (float*)A;
    int minIndex;
    for(int i=0; i<n; i++){
        if(arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }
    return minIndex;
}


int main() {
    int intArr[] = {5, 9, 2, 7, 3};
    float floatArr[] = {4.2, 1.1, 9.9, 0.5, 3.3};

    int maxPos = findpos((void*)intArr, 5, fpMaxInt);
    int minPos = findpos((void*) floatArr, 5, fpMinFloat);
    cout<<"Max Element position in Int Array: "<<maxPos<<endl;
    cout<<"Min Element position in Float Array: "<<minPos<<endl;

    return 0;

}