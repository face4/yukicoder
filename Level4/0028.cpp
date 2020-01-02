// あと1歩考察が及ばず解説を見た
// ボトルネックになるBの素因数を固定する
// という観点を持てなかった

#include<iostream>
#include<vector>
#include<map>
#include<numeric>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int q;
    cin >> q;
    while(q--){
        ll s;
        int n, k, b;
        cin >> s >> n >> k >> b;
        map<int,int> so;
        for(int i = 2; i*i <= b; i++){
            while(b%i==0)  so[i]++, b /= i;
        }
        if(b-1) so[b]++;
        vector<int> v[so.size()];
        vector<int> div;
        for(auto p : so)    div.push_back(p.first);
        for(int i = 0; i <= n; i++){
            ll cp = s;
            for(int j = 0; j < div.size(); j++){
                int tmp = 0;
                while(cp%div[j]==0) tmp++, cp /= div[j];
                v[j].push_back(tmp);
            }
            s = 1 + (s*s+s*12345)%100000009;
        }
        ll ret = 1ll<<60;
        for(int j = 0; j < div.size(); j++){
            sort(v[j].begin(),v[j].end());
            ret = min(ret, accumulate(v[j].begin(),v[j].begin()+k, 0ll)/so[div[j]]);
        }
        cout << ret << endl;
    }
    return 0;
}