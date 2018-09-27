#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

typedef long long ll;
const ll inc = 1000000000;

int n;
ll k;
vector<ll> l;

bool check(ll a){
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += l[i]/a;
        if(cnt >= k)    return true;
    }
    return false;
}

int main(){
    cin >> n;

    l.resize(n);
    for(int i = 0; i < n; i++)  cin >> l[i], l[i] *= inc;

    cin >> k;

    ll lower = 1, upper = inc*inc;
    while(upper - lower > 1){
        ll mid = (upper + lower) / 2;
        if(check(mid))  lower = mid;
        else            upper = mid-1;
    }

    cout << fixed << setprecision(10) << (long double)(lower) / inc << endl;

    return 0;
}