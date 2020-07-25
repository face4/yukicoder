#include<iostream>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    k--;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    if(a[k] == 0){
        cout << 0 << endl;
    }else{
        int l = max(0,k-1), r = min(n-1,k+1);
        while(l-1 >= 0 && a[l] > 1)   l--;
        while(r+1 < n && a[r] > 1)    r++;
        if(a[k] > 1)    cout << accumulate(a+l, a+r+1, 0ll) << endl;
        else            cout << max(accumulate(a+l, a+k+1, 0ll), accumulate(a+k, a+r+1, 0ll)) << endl;
    }
    return 0;
}