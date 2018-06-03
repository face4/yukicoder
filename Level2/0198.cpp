#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
typedef long long ll;

ll b;
vector<ll> A;

ll calc(ll x){
    ll ret = 0;
    for(ll a : A)   ret += abs(x-a);
    return ret;
}

int main(){
    int n;
    cin >> b >> n;

    ll sum = b;
    for(int i = 0; i < n; i++){
        ll t;
        cin >> t;
        A.push_back(t);
        sum += t;
    }

    sort(A.begin(), A.end());

    // 箱に何個入れるかを三分探索
    ll l = A[0];
    ll r = sum / n + 1;

    while(r - l > 2){
        ll mid1 = (l * 2 + r) / 3;
        ll mid2 = (l + 2 * r) / 3;

        if(calc(mid1) > calc(mid2)){
            l = mid1;
        }else{
            r = mid2;
        }
    }

    ll ans = LLONG_MAX;
    for(ll i = l; i < r; i++){
        ans = min(ans, calc(i));
    }

    cout << ans << endl;

    return 0;
}