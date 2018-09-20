#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool b[26] = {};
    for(int i = 0; i < s.length(); i++){
        if(b[s[i]-'A']){
            cout << "NO" << endl;
            return 0;
        }
        b[s[i]-'A'] = true;
    }
    cout << "YES" << endl;
    return 0;
}