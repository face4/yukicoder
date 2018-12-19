#include<iostream>
#include<numeric>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    n++;

    const ll mod = 1e9+7;
    ll a[n], sum = 0;
    for(int i = 0; i < n; i++)  cin >> a[i], sum = (sum+a[i])%mod;

    ll b, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> b;
        b %= mod;
        ans = (ans+b*sum)%mod;
        sum = (sum-a[n-1-i]+mod)%mod;
    }

    cout << ans << endl;

    return 0;
}