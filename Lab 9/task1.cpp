#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
using namespace std;

struct Element{
    string name;
    string symbol;
    int atomicNumber;

    Element(string n, string s, int a): name(n), symbol(s), atomicNumber(a) {}
};

struct Ascend{
    bool operator()(Element& a , Element& b){
        if(a.atomicNumber != b.atomicNumber){
            return a.atomicNumber<b.atomicNumber; //Primary
        } return a.name < b.name; //Secondary
    }
};

struct Count{
    bool operator()(Element& a){
        return a.name.size() > 5;
    }
};

int main(){
    Element e1("Hydrogen", "H", 1);
    Element e2("Oxygen", "O", 8);
    Element e3("Helium", "He", 2);
    vector<Element> elements;
    elements.push_back(e1);
    elements.push_back(e2);
    elements.push_back(e3);
    sort(elements.begin(), elements.end(), Ascend());
    for( Element& e : elements){
        cout<<"Name: "<<e.name<<", Symbol: "<<e.symbol<<", Atomic Number: "<<e.atomicNumber<<endl;

    }
    int count1 = count_if(elements.begin(), elements.end(), Count());
    cout<<count1<<endl;

    vector<string> upperCaseSymbols;
    //transform(start, end, output begin, function)
    transform(elements.begin(), elements.end(), back_inserter(upperCaseSymbols),
    [](const Element& e){
        string upperSymbol = e.symbol;
        for(char& c : upperSymbol){
            c = toupper(c);
        }
        return upperSymbol;
    }
    );
    cout<<"Uppercase symbols: ";
    for(string& s: upperCaseSymbols){
        cout<<s<<" ";
    }
    cout<<endl;

    return 0;
}