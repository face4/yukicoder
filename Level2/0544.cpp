#include<iostream>
using namespace std;

int main(){
    string s, a = "";
    cin >> s;

    int slen = s.length();
    for(int i = 1; i <= slen; i++){
        char c = s[slen-i];
        if(c == '7'){
            a += '1';
        }else{
            a += '0';
        }
    }

    string ax = string(a.rbegin(), a.rend());
    int A = stoi(ax);
    cout << A << " " << (stoi(s)-A) << endl;
    return 0;
}