#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ret = n;
    for(int i = 2; i < 63; i++){
        ll l = 0, r = n;
        while(r-l > 1){
            ll mid = (l+r)/2;
            ll tmp = 0;
            for(int j = 0; j < i; j++){
                tmp += mid;
                mid /= 2;
            }
            mid = (l+r)/2;
            if(tmp >= n)    r = mid;
            else            l = mid;
        }
        ll cp = r;
        ll tmp = 0;
        for(int j = 0; j < i; j++){
            tmp += cp;
            cp /= 2;
        }
        if(tmp == n)    ret = min(ret, r);
    }
    cout << ret << endl;
    return 0;
}