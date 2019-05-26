#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];
    int l = 0, r = 1000000000;
    while(r-l > 1){
        ll cnt = 0;
        int mid = (l+r)/2;
        for(int i = 0; i < n; i++){
            if(mid >= b[i]) cnt += b[i]-a[i]+1;
            else if(mid >= a[i])    cnt += mid-a[i]+1;
        }
        if(cnt >= k)    r = mid;
        else            l = mid;
    }
    cout << r << endl;
    return 0;
}