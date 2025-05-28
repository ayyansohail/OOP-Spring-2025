#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class SS{
    public:
    struct Ascending{
        bool operator()(T a, T b){
            return a < b;
        }
    };

    struct Descending{
        bool operator()(T a, T b){
            return a > b;
        }
    };
};

template<typename T, typename Compare>
void selectionSort(vector<T>& vec, Compare comp){
    for(int i = 0; i<vec.size()-1; i++){
        int minIndex = i;
        for(int j = i+1; j<vec.size(); j++){
            if(comp(vec[j], vec[minIndex])){
                minIndex = j;
            }
            
        }
        swap(vec[i],vec[minIndex]);
    }
}

int main(){
    vector<int> vec = {4,5,3,1,2};
    cout<<"Original: "<<endl;
    for(int n: vec){
        cout<<n<<" ";
    }
    cout<<endl;
    SS<int>::Ascending comp;
    selectionSort(vec, comp);
    cout<<"Sorted: "<<endl;
    for(int n: vec){
        cout<<n<<" ";
    }
    cout<<endl;
}