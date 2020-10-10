#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n], b[n];
    ll sum = 0;
    vector<pii> vp;
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i], sum += b[i], vp.push_back({a[i], b[i]});
    sort(vp.begin(), vp.end());
    ll acc = 0, piv;
    for(int i = 0; i < n; i++){
        acc += vp[i].second;
        if(acc >= (sum+1)/2){
            piv = vp[i].first;
            break;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (ll)b[i] * abs(piv-a[i]);
    }
    cout << piv << " " << ans << endl;
    return 0;
}