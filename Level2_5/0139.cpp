#include<iostream>
using namespace std;

int main(){
    int n, l, x, w, t;
    cin >> n >> l;
    int ans = 0, befpos = 0;

    for(int i = 0; i < n; i++){
        cin >> x >> w >> t;
        ans += x-befpos;
        int residual = t - ans%(2*t);
        if(residual < w)   ans = ( (ans + 2*t - 1) / (2*t) ) * (2*t);   // floor
        ans += w;
        befpos = x+w;
    }

    cout << ans + (l-befpos) << endl;

    return 0;
}