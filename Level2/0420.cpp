#include<iostream>
using namespace std;

typedef long long ll;

ll getcomb(ll a, ll b){
    ll ans = 1;
    for(int i = 1; i <= b; i++){
        ans *= (a-i+1);
        ans /= i;
    }
    return ans;
}

int main(){
    ll max = (1ll<<31)-1;
    
    ll n;
    cin >> n;
    if(n > 31){
        cout << 0 << " " << 0 << endl;
    }else if(n == 0){
        cout << 1 << " " << 0 << endl;
    }else{
        ll comb = getcomb(31,n);
        ll sum = max * getcomb(30,n-1);
        cout << comb << " " << sum << endl;
    }

    return 0;
}