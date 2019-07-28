#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    if(v[0] == v[n-1]){
        cout << 1 << endl;
        return 0;
    }
    vector<ll> sum(n);
    sum[0] = v[0];
    for(int i = 1; i < n; i++)  sum[i] = sum[i-1] + v[i];
    auto f = [&](int l, int r)->ll{
        if(r < 0 || l >= n)  return 0;
        ll sub = (l == 0 ? 0 : sum[l-1]);
        return sum[r] - sub;
    };
    // [i, r] , pivot - k
    auto g = [&](int i, int j, int k)->ll{
        return v[k]*(k-i)-f(i,k-1)+f(k+1,j)-v[k]*(j-k);
    };
    ll ans = 1ll<<60;
    for(int i = 1; i < n; i++){
        ans = min(ans, g(0,i-1,i/2)+g(i,n-1,(n+i)/2));
    }
    cout << ans << endl;
    return 0;
}