#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n+1, 0);
    for(int i = 1; i <= n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    vector<ll> sum = v;
    for(int i = 1; i <= n; i++) sum[i] += sum[i-1];
    ll ans = 0;
    for(int i = 2; i < n; i++){
        if(v[n]-v[i]+v[i-1]-v[i] < 0)   continue;
        int l = 1, r = min(i-1, n-i)+1;
        while(r-l > 1){
            int mid = (l+r)/2;
            if(v[n-mid+1]-v[i]+v[i-mid]-v[i] >= 0)  l = mid;
            else                                    r = mid;
        }
        ans = max(ans, sum[n]-sum[n-l]+sum[i-1]-sum[i-1-l]-2*l*v[i]);
    }
    cout << ans << endl;
    return 0;
}