#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class IS{

    public:
    struct Ascending {
        bool operator()(T a, T b){
            return a < b;
        }
    };
    struct Descending {
        bool operator()(T a, T b){
            return a > b;
        }
    };
};

template<typename T, typename Compare>
void insertionSort(vector<T>& vec, Compare comp){
    for(int i = 1; i<vec.size(); i++){
        int curr = vec[i];
        int prev = i-1;
        while(prev >= 0 && comp(curr, vec[prev])){
            vec[prev+1] = vec[prev];
            prev--;
        }
        vec[prev+1] = curr;
    }
};

int main() {
    vector<int> vec = {5,2,3,4,1};
    cout<<"Original: "<<endl;
    for(int n: vec){
        cout<<n<<" ";
    }
    cout<<endl;
    IS<int>::Ascending comp; //You can interchange bw Ascending and Descending 
    insertionSort(vec, comp);
    cout<<"Sorted Ascending: "<<endl;
    for(int n: vec){
        cout<<n<<" ";
    }
}