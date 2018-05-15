#include<iostream>
using namespace std;
#define MAX 1000001
#define MOD 1000000007

typedef long long ll;

ll dpken2[MAX] = {};
ll dpken[MAX] = {};
ll dppa[MAX] = {};

int main(){
    dpken[1] = 1;

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        dppa[i] = (dpken[i-1]+dpken2[i-1])%MOD;
        dpken[i] = dppa[i-1];
        dpken2[i] = dpken[i-1];
    }

    ll ans = (dppa[n]+dpken[n]+dpken2[n])%MOD;

    cout << ans << endl;

    return 0;
}