#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    bool b = true;
    for(int i = 0; i < n; i++)  b &= s[0]==s[i];
    if(b){
        cout << -1 << endl;
        return 0;
    }
    int nonzero = 0;
    for(char c : s) nonzero += c != '0';
    if(nonzero == 1){
        cout << -1 << endl;
        return 0;
    }
    sort(s.rbegin(), s.rend());
    for(int i = n-1; i >= 1; i--){
        if(s[i] != s[i-1]){
            swap(s[i], s[i-1]);
            break;
        }
    }
    cout << s << endl;
    return 0;
}