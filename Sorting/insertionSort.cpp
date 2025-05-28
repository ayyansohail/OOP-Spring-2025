#include<iostream>
using namespace std;

/*
Builds the sorted array one element at a time by:

Taking the next element,

Inserting it into its correct position in the sorted part (like placing cards in a hand).

Time Complexity: Average->O(n^2), Best->O(n)
*/

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){  // {5,3,4,1,2}
        int current = arr[i]; // CURRENT = 3
        int prev = i - 1; // prev = 0
        while(prev >= 0 && arr[prev] > current){  // prev = 0 && 5 > 3
            arr[prev+1] = arr[prev]; // arr[1] = arr[0]; {5,5,4,1,2}
            --prev; // prev = -1
        }
        arr[prev+1] = current; //arr[0] = 3; {3,5,4,1,2}
    }
    }

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[5] = {5,3,4,1,2};
    insertionSort(arr, 5);
    display(arr,5);

}