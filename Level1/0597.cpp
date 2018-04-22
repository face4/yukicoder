#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    int n;
    getline(cin, s);
    n = stoi(s);
    while(n-- > 0){
        getline(cin, s);
        cout << s;
    }
    cout << endl;
    return 0;
}