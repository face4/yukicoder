#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    map<int, vector<int>> m;
    int a;
    while(n-- > 0){
        cin >> a;
        for(int i = 2; i*i <= a; i++){
            int cnt = 0;
            while(a%i == 0) a /= i, cnt++;
            if(cnt) m[i].push_back(cnt);
        }
        if(a != 1)  m[a].push_back(1);
    }

    ll ans = 1;
    for(auto p : m){
        sort(p.second.rbegin(), p.second.rend());
        ll sum = 0;
        for(int i = 0; i < min((int)(p.second.size()), k); i++){
            sum += p.second[i];
        }
        ans *= modpow(p.first, sum, mod);
        ans %= mod;
    }
    
    cout << ans << endl;

    return 0;
}