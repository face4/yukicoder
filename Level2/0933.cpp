#include<iostream>
using namespace std;

typedef long long ll;

void fold(ll &x){
    while(x >= 10){
        ll tmp = 0;
        while(x)    tmp += x%10, x/=10;
        x = tmp;
    }
}

int main(){
    int n;
    cin >> n;
    ll x = 1;
    for(int i = 0; i < n; i++){
        ll y;   cin >> y;
        x *= y;
        fold(x);
    }
    cout << x << endl;
    return 0;
}