#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll x[200001] = {};
    for(int i = 0; i < n; i++){
        int a;  cin >> a;
        x[a]++;
    }
    ll ans = 0, sum = x[1], rsum = 0, num = 0;
    // i is divisor
    for(int i = 2; i <= 200000; i++){
        rsum += num;
        num += x[i];
        ans += sum*x[i];
        sum += x[i]*i;
        // j is dividend
        for(int j = 2; j*j <= i; j++){
            if(i%j) continue;
            rsum -= x[j]*j;
            if(j*j == i)    break;
            rsum -= x[i/j]*(i/j);
        }
        ans += rsum*x[i];
    }
    cout << ans << endl;
    return 0;
}