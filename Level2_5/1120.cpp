#include<iostream>
#include<numeric>
using namespace std;
typedef long long ll;

void ng(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    ll asum = accumulate(a, a+n, 0ll);
    ll bsum = accumulate(b, b+n, 0ll);
    if(n == 2){
        cout << (asum==bsum ? abs(a[0]-b[0]) : -1) << endl;
        return 0;
    }
    if(bsum > asum || (asum-bsum)%(n-2) > 0)    ng();
    ll ans = (asum-bsum)/(n-2);
    for(int i = 0; i < n; i++){
        if(a[i]-ans > b[i] || (b[i]-a[i]+ans)%2)    ng();
    }
    cout << ans << endl;
    return 0;
}