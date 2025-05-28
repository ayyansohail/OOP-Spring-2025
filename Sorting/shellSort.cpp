#include<iostream>
using namespace std;

/*
Shell Sort is an optimized version of Insertion Sort. It:

Starts by sorting elements far apart (with a gap),

Gradually reduces the gap to 1 (making it become insertion sort at the end).

Time Complexity: Best->O(nlogn), Average->O(n^3/2), Worst -> O(n^2)
*/
// Array = 5,3,2,1,4; n = 5
void shellSort(int arr[], int n){
    for(int gap = n/2; gap>0; gap /= 2){ //Start with a large gap then reduce the gap; gap = 2
        //Do a gapped insertion sort for this gap
        for(int i = gap ; i < n; i++){
            int temp = arr[i]; // temp = arr[2] = 2
            int j;

            for(j = i; j >= gap && arr[j - gap] > temp; j-=gap){ // j = 2; arr[0] > arr[2] = 5 > 2; 
                arr[j] = arr[j - gap]; //arr[2] = arr[0]; arr[2] = 5; array -> 5,3,5,1,4
            }
            arr[j] = temp; // arr[0] = 2; array -> 2,3,5,1,4
        }

    }
}

void display(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[5] = {5,3,2,1,4};
    shellSort(arr, 5);
    cout<<"Sorted Array: ";
    display(arr, 5);

    return 0;
}