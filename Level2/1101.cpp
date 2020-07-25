#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll v, t, p;
    cin >> v >> t >> p;
    ll ret = v*(p+1)+1;
    ll res = ret-1;
    while(res >= t){
        ll add = res/t;
        ret += add;
        res %= t;
        res += add;
    }
    cout << ret << endl;
    return 0;
}