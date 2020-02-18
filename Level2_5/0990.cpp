#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a%b);
}

int main(){
    int n, m, k;
    char op;
    cin >> n >> m >> k >> op;
    vector<ll> b(m), a(n);
    for(int i = 0; i < m; i++)  cin >> b[i];
    for(int i = 0; i < n; i++)  cin >> a[i];
    ll ret = 0;
    if(op == '+'){
        map<int,int> cnt;
        for(int i = 0; i < m; i++)  cnt[b[i]%k]++;
        for(int i = 0; i < n; i++)  ret += cnt[(k-a[i]%k)%k];
    }else if(op == '*'){
        map<ll,ll> bcnt, acnt;
        for(int i = 0; i < m; i++){
            bcnt[gcd(b[i], k)]++;
        }
        for(int i = 0; i < n; i++){
            acnt[gcd(a[i], k)]++;
        }
        for(auto p : bcnt){
            for(auto q : acnt){
                if(p.first*q.first%k==0)    ret += p.second*q.second;
            }
        }
    }
    cout << ret << endl;
    return 0;
}