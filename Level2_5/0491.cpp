// プロの解説ブログを見た
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    n /= (ll)1e9+1;

    int ans = 0;
    for(ll i = 1; i < 100000; i++){
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        
        // 偶数長の回文
        ll tmp = stoll(s+t);
        if(tmp <= n)    ans++;
        
        // 奇数長の回文
        if(s.back() == t.front()){
            s.pop_back();
            tmp = stoll(s+t);
            if(tmp <= n)    ans++;
        }
    }

    cout << ans << endl;

    return 0;
}