#include<iostream>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a%b);
}

int a, b, n;
ll ret = 1;
const ll mod = 1e9+7;

void dfs(int i, ll x){
    if(i == n){
        ret = ret*x%mod;
        return;
    }
    for(int j = a; j <= b; j++){
        dfs(i+1, i==0?j:gcd(x,j));
    }
}

int main(){
    cin >> a >> b >> n;
    dfs(0, 1);
    cout << ret << endl;
    return 0;
}