#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct BalancedBraces{
    bool operator()(const string& expression){
        int count = 0;
        for(char c : expression){
            if( c == '{'){
                count++;
            } else if(c == '}'){
                if(count == 0){
                    return false;
                }
                count--;
            }
        }
        return count == 0;
    }
};

int main() {
    BalancedBraces checker;
    vector<string> expressions = {"{a+b}","{}}","{{}}","{}"};
    for(string& expr: expressions){
        cout<<"Expression: "<<expr<<" is ";
        cout<<(checker(expr)?"Balanced " : "Unbalanced ")<<endl;
    }

    int count = count_if(expressions.begin(), expressions.end(), checker);
    cout<<"No. of balanced expressions: "<<count<<endl;

    return 0;
}
