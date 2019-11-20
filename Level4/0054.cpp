// kmjpさんの解説を読んだ
// v1,t1 と v2,t2について1->2がokで2->1がダメなとき、
// v1 < t2 かつ v2 >= t1より、
// v1+t1 < v2+t2
// 1を先に回った方が良いことから、(v+t)昇順に回るのが
// 良いとわかる
// 面白い
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a+b, b});
    }
    sort(vp.begin(), vp.end());
    bool dp[20000] = {};
    dp[0] = true;
    for(pair<int,int> p : vp){
        for(int j = p.second-1; j >= 0; j--){
            dp[j+p.first-p.second] |= dp[j];
        }
    }
    for(int j = 19999;;j--){
        if(dp[j]){
            cout << j << endl;
            return 0;
        }
    }
}