#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    
    vector<pair<int,int>> v;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.rbegin(), v.rend(), [](pair<int,int> p, pair<int,int> q){return p.second < q.second;});
    
    int buy = n/3*2;
    if(n%3 == 1)    buy++;
    else if(n%3 == 2)   buy += 2;

    vector<ll> dp(buy, 1ll<<60);
    for(int i = 0; i < n; i++){
        for(int j = buy-1; j > 0; j--){
            dp[j] = min(dp[j], dp[j-1]+v[i].first+(ll)v[i].second*j);
        }
        dp[0] = min(dp[0], (ll)v[i].first);
    }
    cout << dp[buy-1] << endl;
    return 0;
}