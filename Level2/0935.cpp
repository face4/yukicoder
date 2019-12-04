#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> e(n, 0);
    for(int i = 0; i < n; i++){
        if(i)   e[i] += e[i-1];
        e[i] += s[i]=='E';
    }
    vector<ll> sum(n);
    for(int i = 0; i < n; i++){
        cin >> sum[i];
        if(i)   sum[i] += sum[i-1];
    }
    vector<ll> need(n+1, 1ll<<60);
    need[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int tmp = e[j] - (i==0 ? 0 : e[i-1]);
            if(tmp == 0)    continue;
            ll p = sum[j] - (i==0 ? 0 : sum[i-1]);
            need[tmp] = min(need[tmp], p);
        }
    }
    int q;
    cin >> q;
    while(q-- > 0){
        ll k;
        cin >> k;
        for(int j = n; j >= 0; j--){
            if(need[j] <= k){
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}