#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n, k;
    cin >> n >> k;

    int x[k], y[k];
    for(int i = 0; i < k; i++){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int to = i;
        for(int j = 0; j < k; j++){
            if(x[j] == to){
                to = y[j];
            }else if(y[j] == to){
                to = x[j];
            }
        }
        v[i] = to;
    }

    ll ans = 1;
    for(int i = 0; i < n; i++){
        ll cnt = 1;
        int pos = i;
        while(v[pos] != i)  pos = v[pos], cnt++;
        ll g = gcd(ans, cnt);
        ans = ans*cnt/g;
    }

    cout << ans << endl;

    return 0;
}