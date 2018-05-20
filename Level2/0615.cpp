#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    ll A[n];
    ll diff[n-1] = {};

    for(int i = 0; i < n; i++)  cin >> A[i];
    sort(A, A+n);

    for(int i = 0; i < n-1; i++){
        diff[i] = A[i+1]-A[i];
    }
    
    sort(diff, diff+n-1);

    ll ans = 0;
    for(int i = 0; i < n-k; i++){
        ans += diff[i];
    }

    cout << ans << endl;

    return 0;
}