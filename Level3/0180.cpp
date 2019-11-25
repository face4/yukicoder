// 解説を読んだ
#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    auto f = [&](ll x)->ll{
        ll ma = 0, mi = 1ll<<60;
        for(int i = 0; i < n; i++){
            ma = max(ma, a[i]+b[i]*x);
            mi = min(mi, a[i]+b[i]*x);
        }
        return ma-mi;
    } ;

    // 二分探索(AC)
    // int l = 1, r = 2e9+1;
    // while(r-l > 1){
    //     int mid = (l+r)/2;
    //     ll x = f(mid-1), y = f(mid);
    //     if(x > y)   l = mid;
    //     else        r = mid;
    // }
    // cout << l << endl;
    
    // 三分探索(AC) 
    // 最小値を達成するxが複数存在する場合に小さい方のxが得られるようにするために探索区間の右端rを削る方を優先
    int l = 0, r = 2e9+1;
    while(r-l > 2){
        int midl = l + (r-l)/3, midr = l + (r-l)/3*2;
        if(f(midl) <= f(midr))  r = midr;
        else                    l = midl;
    }

    cout << l+1 << endl;
    return 0;
}
