#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll a[4] = {}, b[4] = {}, l[4], r[4];
    for(int i = 1; i <= 3; i++)  cin >> a[i];
    for(int i = 1; i <= 3; i++)  cin >> b[i];
    for(int i = 1; i <= 3; i++){
        ll sum = 0;
        for(int j = 1; j <= i; j++)  sum += b[j];
        l[i] = (sum-1)*a[i]+1, r[i] = sum*a[i];
    }
    ll low = 0, high = 1ll<<60;
    for(int i = 1; i <= 3; i++){
        low = max(low, l[i]);
        high = min(high, r[i]);
    }
    if(low <= high) cout << low << " " << high << endl;
    else            cout << -1 << endl;
    return 0;
}