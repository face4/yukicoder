#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    ll k;
    char op;
    cin >> n >> m >> k >> op;
    vector<ll> b(m), a(n);
    for(int i = 0; i < m; i++)  cin >> b[i];
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ret = 0;
    for(int i = 0; i < n; i++){
        ll val = op=='+' ? k-a[i] : (k+a[i]-1)/a[i];
        ret += m-(lower_bound(b.begin(),b.end(),val)-b.begin());
    }
    cout << ret << endl;
    return 0;
}