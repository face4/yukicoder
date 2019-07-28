#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

map<int, ll> fact;
int ans = 0;
ll m;

void dfs(map<int,ll>::iterator it, ll val){
    if(it == fact.end()){
        ans++;
        return;
    }
    map<int,ll>::iterator next = it;
    next++;
    for(int i = 0; i <= it->second; i++){
        if(val > m)   break;
        dfs(next, val);
        val *= it->first;
    }
}

int main(){
    ll n, k;
    cin >> n >> k >> m;
    for(int i = 2; i*i <= n; i++){
        while(n%i == 0){
            n /= i;
            fact[i]++;
        }
    }
    if(n != 1)  fact[n]++;
    for(auto p : fact)  fact[p.first] = p.second*k;
    dfs(fact.begin(), 1);
    cout << ans << endl;
    return 0;
}