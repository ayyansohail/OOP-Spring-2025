#include<iostream>
using namespace std;

/*
Selection Sort divides the array into sorted and unsorted parts. It repeatedly:

Finds the minimum element from the unsorted part,

Puts it at the beginning of the unsorted part (effectively growing the sorted part).

Time Complexity = O(n^2)
*/

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[5] = {5,2,4,1,3};
    selectionSort(arr,5);
    display(arr,5);

    return 0;
}