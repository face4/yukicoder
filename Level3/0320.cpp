#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll m;

    cin >> n >> m;

    vector<ll> fib(81);
    fib[1] = fib[2] = 1;
    for(int i = 3; i < 81; i++) fib[i] = fib[i-1] + fib[i-2];

    ll diff = fib[n]-m;

    if(diff < 0){
        cout << -1 << endl;
        return 0;
    }

    // fib[1]とfib[2]を間違えることはないので、
    // 引くことが出来るのは最大でもfib[n-2]
    int cnt = 0;
    for(int i = n-2; i > 0; i--){
        if(diff >= fib[i])  diff -= fib[i], cnt++;
    }

    if(diff)    cout << -1 << endl;
    else        cout << cnt << endl;

    return 0;
}