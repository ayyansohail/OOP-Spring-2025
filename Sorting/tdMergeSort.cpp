#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void merge(vector<T>& a, vector<T>& aux, int l, int m, int r){
    //Copy to auxillary Array
    for(int k = l; k <= r; k++){
        aux[k] = a[k];
    }

    int i = l, j = m + 1;  // i starts for left half, j starts for right half(m+ 1)
    for(int k = l; k <= r; k++){ // k is where we start writing the next smallest element from
        if( i > m) a[k] = aux[j++]; //left half is exhausted
        else if (j > r) a[k] = aux[i++]; //right half is exhausted
        else if (aux[j] < aux[i]) a[k] = aux[j++]; //right smaller -> pick from right
        else a[k] = aux[i++]; //left smaller or equal -> pick from left
    }
}

template<typename T>
void sort(vector<T>& a, vector<T>& aux, int l, int r){
    if(r <= l) return; //Base Case: if arr has 0 or 1 elements, its already sorted
    int m = l + (r - l)/2; // compute middle index
    sort(a , aux, l, m); //sort left half
    sort(a, aux, m+1, r); //sort right half
    merge(a, aux, l, m, r); //merge sorted halves into one
}

template<typename T>
void sort(vector<T>& a){
    vector<T> aux(a.size()); //create helper array
    sort(a, aux, 0, a.size() - 1); //start recursive sort
}

template<typename T>
void display(vector<T>& a){
    for(T n : a){
        cout<<n<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> a = {5,2,3,1,4};
    sort(a);
    display(a);

    return 0;
}