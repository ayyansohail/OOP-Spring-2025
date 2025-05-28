#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

template<typename T>
class NumberStats{

    private:
    vector<T> numbers;

    public:
    void addNum(T num){
        numbers.push_back(num);
    }
    T getMin() const {
        if(numbers.empty()){
            throw runtime_error("Vector is empty");
        }
        return *min_element(numbers.begin(), numbers.end());
        
    }

    T getMax() const {
        if(numbers.empty()){
            throw runtime_error("Vector is empty");
        }
        return *max_element(numbers.begin(), numbers.end());
    }

    double getAvg() const {
        if(numbers.empty()){
            throw runtime_error("Vector is empty");
        }
        double sum = accumulate(numbers.begin(), numbers.end(), 0.0);
        return sum/numbers.size();
    }

};

int main () {

    NumberStats<int> statsInt;
    statsInt.addNum(5);
    statsInt.addNum(2);
    statsInt.addNum(8);

    cout<<"Minimum: "<<statsInt.getMin()<<endl;
    cout<<"Maximum: "<<statsInt.getMax()<<endl;
    cout<<"Average: "<<statsInt.getAvg()<<endl;

    return 0;
}
