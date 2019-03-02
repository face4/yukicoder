#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    ll x[3], y[3];
    for(int i = 0; i < 3; i++)  cin >> x[i] >> y[i];
    ll ans = x[2];
    for(int i = 0; i <= y[1]; i++){
        if(ans%y[1] == x[1])   break;
        ans += y[2];
    }
    ll g = y[2]*y[1]/gcd(y[2], y[1]);
    for(int i = 0; i <= y[0]; i++){
        if(ans%y[0] == x[0])   break;
        ans += g;
    }
    bool valid = true;
    for(int i = 0; i < 3; i++)  valid &= (ans%y[i])==x[i];
    if(valid && ans == 0){
        ans = y[2]*y[1]/gcd(y[2],y[1]);
        ans = ans*y[0]/gcd(ans,y[0]);
    }
    cout << (valid ? ans : -1) << endl;
    return 0;
}