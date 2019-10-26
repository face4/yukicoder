#include<iostream>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    string s;
    getline(cin, s);
    bool ok = true;
    for(int i = 0; i < s.length(); i++){
        if(i%2) ok &= s[i]==' ';
        else    ok &= inRange(s[i],'a','z');
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}