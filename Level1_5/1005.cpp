#include<iostream>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    if(t.length() == 1){
        for(char c : s){
            if(c == t[0]){
                cout << -1 << endl;
                return 0;
            }
        }
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    int tlen = t.length(), slen = s.length();
    for(int i = 0; i+tlen <= slen;){
        if(s.substr(i, tlen) == t){
            ans++;
            i += tlen-1;
        }else{
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}