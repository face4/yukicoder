#include<iostream>
using namespace std;

bool f(string s, string t){
    if(s.length() < t.length()) return true;
    if(s.length() > t.length()) return false;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == t[i])    continue;
        return s[i] < t[i];
    }
}

int main(){
    string a, b, pa, pb, x;
    cin >> a >> pa >> x >> b >> pb >> x;
    if(pa == pb){
        cout << -1 << endl;
    }else{
        cout << (f(pa,pb) ? b : a) << endl;
    }
    return 0;
}