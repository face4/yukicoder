#include<iostream>
#include<map>
using namespace std;

typedef long long ll;
map<ll, ll> memo;

ll dfs(ll n){
    if(n == 0)  return 1;
    if(memo.count(n))   return memo[n];
    return memo[n] = dfs(n/3) + dfs(n/5);
}

int main(){
    ll n;
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}