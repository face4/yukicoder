#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pii> v;
    for(int i = 0; i < n; i++){
        int p, d;
        cin >> p >> d;
        v.push_back({p, d});
    }
    sort(v.rbegin(), v.rend());
    vector<int> dp1(k+1, -1), dp2(k+1, -1);
    dp1[0] = 0;
    for(int i = 0; i < n; i++){
        vector<int> ndp1 = dp1, ndp2 = dp2;
        for(int j = k; j >= 0; j--){
            if(dp1[j] != -1 && j+v[i].first <= k){
                ndp2[j+v[i].first] = max(ndp2[j+v[i].first], dp1[j]+v[i].second);
            }
            if(dp2[j] != -1){
                ndp1[j] = max(ndp1[j], dp2[j]+v[i].second);
                ndp2[j] = max(ndp2[j], dp2[j]);
            }
        }
        dp1 = ndp1, dp2 = ndp2;
    }
    cout << max(*max_element(dp1.begin(),dp1.end()), *max_element(dp2.begin(),dp2.end())) << endl;
    return 0;
}