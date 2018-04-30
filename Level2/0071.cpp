#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    ll ans;

    cin >> n;
    n += 2;
    if(n % 2 == 1){
        ans = (n/2) * (n/2 + 1) - 1;
    }else{
        ans = (n/2) * (n/2) - 1;
    }

    cout << ans << endl;
    return 0;
}