#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printVector(const vector<int>& arr){
    for(int num : arr){
        cout<<num<<" ";
    }
    cout<<endl;
}

//Sorting Array
void sortArray(vector<int>& arr){
    sort(arr.begin(), arr.end());
        cout<<"Sorted: "<<endl;
        printVector(arr);
}

//Reversing Array
void reverseArray(vector<int>& arr){
    reverse(arr.begin(), arr.end());
    cout<<"Reversed: "<<endl;
    printVector(arr);
}

//Rotating Array
void rotateArray(vector<int>& arr){
    if(!arr.empty()){
    rotate(arr.begin(), arr.begin() + 1, arr.end());
    cout<<"Rotated: "<<endl;
    printVector(arr);
    }
}

//Finding the minimum element 
void minElement(vector<int>& arr){
   auto minIt = min_element(arr.begin(), arr.end());
   cout<<"Minimum: "<<*minIt<<endl;
}

//Finding the max element 
void maxElement(vector<int>& arr){
    auto maxIt = max_element(arr.begin(), arr.end());
    cout<<"Maximum: "<<*maxIt<<endl;
}

//Counting occurences of a specific value
void countOccurence(vector<int>& arr){
    int value = 2;
    int countVal = count(arr.begin(), arr.end(), value);
    cout<<"Count of value "<<value<<": "<<countVal<<endl;
}

void custom_algorithm(vector<int>& arr, void (*operation)(vector<int>& arr)){
    operation(arr);
}

int main() {

    vector<int> arr = {5,2,9,1,2};
    cout<<"Original Array: ";
    printVector(arr);

    custom_algorithm(arr, sortArray);
    custom_algorithm(arr, reverseArray);
    custom_algorithm(arr, rotateArray);
    custom_algorithm(arr, minElement);
    custom_algorithm(arr, maxElement);

    countOccurence(arr);

    return 0;
}
