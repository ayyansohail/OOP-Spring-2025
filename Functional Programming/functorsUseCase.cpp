#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Use Case: Custom Comparator

struct Descend {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    vector<int> v = {1,3,2};
    sort(v.begin(), v.end(), Descend()); //Uses Functor
    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}