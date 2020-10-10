#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ret = n;
    for(ll i = 2; i <= 7; i++){
        ll cnt = 0, tmp = 1;
        while(tmp < n){
            tmp *= i;
            cnt++;
        }
        ret = min(ret, i*cnt);
    }
    cout << ret << endl;
    return 0;
}