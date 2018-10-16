#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    if(n % 2 == 1){
        cout << "NO" << endl;
    }else{
        if(s.substr(0, n/2) == s.substr(n/2)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}