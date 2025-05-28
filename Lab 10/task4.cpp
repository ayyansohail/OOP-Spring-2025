#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class SS{

    public:
    struct Ascend{
        bool operator()(T a, T b){
            return a < b;
        }
    };
    struct Descend{
        bool operator()(T a, T b){
            return a > b;
        }
    };
};

template<typename T, typename Compare>
void shellSort(vector<T>& vec, Compare comp){
    for(int gap = vec.size()/2; gap>0 ; gap /=2){
        for(int i = gap; i<vec.size(); i++){
            int temp = vec[i];
            int j;

            for(int j = i; j >= gap && comp(vec[j - gap], temp); j++){
                vec[j] = vec[j - gap];
            }
        }
    }
}

int main() {
    vector<int> vec = {4,3,5,1,2};
    SS<int>::Ascend comp;
    shellSort(vec, comp);
    for(int n: vec){
        cout<<n<<" ";
    } cout<<endl;
}