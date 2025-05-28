#include<iostream>
#include<vector>
using namespace std;

// Lomuto partitioning: returns index of pivot after partitioning
int partition(vector<int>& a, int l, int r){
    int pivot = a[r]; //choose the highest element as pivot
    int i = l - 1;   // i is boundary for elements <= pivot

    for(int j = l; j < r; j++){
        if(a[j] < pivot){
            i++; // expand left region
            swap(a[i],a[j]); //move a[j] to left region
        }
    }

    swap(a[i+1],a[r]); // place pivot after last smaller element
    return i + 1;  //return pivot's final position
}

void quickSort(vector<int>& a, int l, int r){
    if (l < r){
        int p = partition(a,l,r); // Lamuto Partition
        quickSort(a,l,p-1); // Recursively sort left array
        quickSort(a,p+1,r); // Recursively sort right array
    }
}

void display(vector<int>& a){
    for(int n : a){
        cout<<n<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {5,3,4,1,2};
    quickSort(arr,0,4);
    display(arr);

    return 0;
}