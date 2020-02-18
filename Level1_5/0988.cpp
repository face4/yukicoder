#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    char op;
    cin >> op;
    vector<ll> b(m), a(n);
    for(int i = 0; i < m; i++)  cin >> b[i];
    for(int i = 0; i < n; i++)  cin >> a[i];
    ll ret = 0;
    if(op == '+'){
        for(int i = 0; i < m; i++)  (ret += b[i]*n%k) %= k;
        for(int i = 0; i < n; i++)  (ret += a[i]*m%k) %= k;
    }else{
        ll asum = accumulate(a.begin(),a.end(),0ll)%k;
        for(int i = 0; i < m; i++)  (ret += asum*b[i]%k) %= k;
    }
    cout << ret << endl;
    return 0;
}