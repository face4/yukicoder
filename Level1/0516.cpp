#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    int res = 0;
    for(; cin >> s;){
        if(s == "RED")       res++;
        else if(s == "BLUE") res--;
    }
    if(res > 0)     cout << "RED";
    else            cout << "BLUE";
    cout << endl;
    return 0;
}