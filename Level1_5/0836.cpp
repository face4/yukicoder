#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ll l, r, n;
    scanf("%lld %lld %lld", &l, &r, &n);

    vector<int> ans(n, 0);

    while(l % n != 0 && l <= r){
        ans[l%n]++;
        l++;
    }

    ll bias = (r-l)/n;

    l += bias * n;
    while(l <= r){
        ans[l%n]++;
        l++;
    }

    for(int i = 0; i < n; i++){
        printf("%lld\n", ans[i]+bias);
    }
    
    return 0;
}