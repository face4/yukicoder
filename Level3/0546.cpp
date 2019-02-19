// 包除原理？
#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n, l, h;
    cin >> n >> l >> h;
    int c[n];
    for(int i = 0; i < n; i++)  cin >> c[i];
    ll ret = 0;
    for(int s = 1; s < 1<<n; s++){
        int pop = 0; ll accum = 1;
        for(int i = 0; i < n; i++){
            if(accum > h)   break;
            if((s>>i)&1)    pop++, accum = accum * c[i] / gcd(accum, c[i]);
        }
        if(accum > h)   continue;
        ll x = (l+accum-1)/accum, y = h/accum;
        ret += (2*(pop%2)-1) * (y-x+1) * pop;
    }
    cout << ret << endl;
    return 0;
}