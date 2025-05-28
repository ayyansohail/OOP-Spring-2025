#include<iostream>
#include<vector>
using namespace std;

// Merges two sorted subarrays: a[l..m] and a[m+1..r]
template<typename T>
void merge(vector<T>& a, vector<T>& aux, int l, int m, int r){
    // Step 1: Copy a[l..r] to aux[l..r]
    for (int k = l; k <= r; k++) {
        aux[k] = a[k];
    }

    // Step 2: Initialize two pointers to the beginning of each sorted half
    int i = l;        // pointer for left half
    int j = m + 1;   // pointer for right half

        for(int k = l; k <= r; k++){ // k is where we start writing the next smallest element from
        if( i > m) a[k] = aux[j++]; //left half is exhausted
        else if (j > r) a[k] = aux[i++]; //right half is exhausted
        else if (aux[j] < aux[i]) a[k] = aux[j++]; //right smaller -> pick from right
        else a[k] = aux[i++]; //left smaller or equal -> pick from left
    }
}

template<typename T>  //Bottom Up Merge Sort Driver
void bottomUpSort(vector<T>& a){
    int N = a.size();
    vector<T> aux(N); //Aux array of same length as a

    //sz is subarray size : 1,2,4,8
    for( int sz = 1; sz < N; sz = sz + sz){
        //Merge subarrays in pair [l..m] & [m+1..r]
        for(int l = 0; l < N - sz; l += sz + sz){
            int m = l + sz - 1;
            int r = min(l + sz + sz -1, N - 1); //Dont go out of bounds
            merge(a,aux,l,m,r);
        }
    }
}

template<typename T>
void display(vector<T>& a){
    for(T n : a){
        cout<<n<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> a {5,3,8,6,2,7,4,1};
    cout<<"Original Array: ";
    display(a);
    bottomUpSort(a);
    cout<<"Sorted Array: ";
    display(a);

    return 0;
}