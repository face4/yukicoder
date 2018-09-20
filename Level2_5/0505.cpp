#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n, x;
    ll a, b;

    cin >> n >> a;
    b = a;
    
    for(int i = 1; i < n; i++){
        cin >> x;
        ll na = max({a, a*x, a+x, a-x, b, b*x, b+x, b-x});
        ll nb = min({a, a*x, a+x, a-x, b, b*x, b+x, b-x});
        if(x)   na = max(na, a/x), nb = min(nb, b/x);
        a = na, b = nb;
    }

    cout << a << endl;

    return 0;
}