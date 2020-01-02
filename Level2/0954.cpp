#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    ll a[5];
    for(int i = 4; i >= 0; i--) cin >> a[i];
    vector<ll> v({1, 1});
    int k = 2;
    while(v.back() <= 100000'00000'00000){
        v.push_back(v[k-1]+v[k-2]);
        k++;
    }
    int ans = 0;
    for(int i = 0; i < k; i++){
        int j = 0;  // 変数の初期化忘れによって答えが変わってしまう
        while(i+j < k && j < 5 && a[j]==v[i+j]) j++;
        ans = max(ans, j);
    }
    cout << ans << endl;
    return 0;
}