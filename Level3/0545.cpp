#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    int n2 = n/2;
    vector<ll> k(n), x, y;
    ll a, b, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        k[i] = a+b;
        sum += a;
    }
    for(int i = 0; i < 1<<n2; i++){
        ll tmps = 0;
        for(int j = 0; j < n2; j++) if((i>>j)&1)    tmps += k[j];
        x.push_back(tmps);
    }
    for(int i = 0; i < 1<<(n-n2); i++){
        ll tmps = 0;
        for(int j = 0; j < n-n2; j++) if((i>>j)&1)    tmps += k[n2+j];
        y.push_back(tmps);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = sum;
    for(int i = 0; i < x.size(); i++){
        ll tmp = sum-x[i];
        auto it = lower_bound(y.begin(), y.end(), tmp);
        if(it != y.end()){
            ans = min(ans, abs(sum-(x[i]+*it)));
            it++;
            if(it != y.end())   ans = min(ans, abs(sum-(x[i]+*it)));
            it--;
        }   
        if(it != y.begin()){
            it--;
            ans = min(ans, abs(sum-(x[i]+*it)));
        }
    }
    cout << ans << endl;
    return 0;
}