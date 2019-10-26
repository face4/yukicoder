#include<iostream>
#include<map>
using namespace std;

int gcd(int a, int b){
    return b==0 ? a : gcd(b, a%b);
}

typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<int,ll> dp;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        map<int,ll> ndp = dp;
        int x;  cin >> x;
        for(auto p : dp)    ndp[gcd(p.first,x)] += p.second;
        dp = ndp;
    }
    cout << dp[1] << endl;
    return 0;
}