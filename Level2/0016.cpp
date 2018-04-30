#include<iostream>
using namespace std;

#define MOD 1000003
typedef long long ll;

ll pow(ll x, unsigned int a){
    ll ans = 1, tmp = x;
    while(a != 0){
        if(a & 1 == 1){
            ans = (ans*tmp)%MOD;
        }
        a = a >> 1;
        tmp = (tmp*tmp)% MOD;
    }
    return ans;
}

int main(){
    int x, n, a;
    cin >> x >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        ans += pow(x, a);
        ans %= MOD;
    }

    cout << ans << endl;
}