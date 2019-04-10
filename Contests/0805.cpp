#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != 'M') continue;
        for(int j = 1; i-j >= 0 && i+j < n; j++){
            if(s[i-j] == 'U' && s[i+j] == 'G')  ans++;
        }
    }
    cout << ans << endl;
    return 0;
}