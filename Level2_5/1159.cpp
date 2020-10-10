#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v(n, 0);
    for(int i = n-3; i >= 0; i--){
        v[i] = s.substr(i,3)=="ing";
    }
    int res = accumulate(v.begin(), v.end(), 0);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i])    res--;
        if(s[i] == 'S') ans += res;
    }
    cout << ans << endl;
    return 0;
}