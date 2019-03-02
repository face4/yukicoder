#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s[0] != '1' || s.length() == 1){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i < s.length(); i++){
        if(s[i] != '3'){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << s.length()-1 << endl;
    return 0;
}