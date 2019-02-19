#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(2*n), plus(100001, 0), minus(100001, 0);
    int z = 0;
    for(int i = 0; i < 2*n; i++){
        cin >> v[i];
        if(v[i] > 0)        plus[v[i]]++;
        else if(v[i] < 0)   minus[-v[i]]++;
        else                z++;
    }

    sort(v.begin(), v.end());
    
    int d = 0, w = 0, m = 0;

    // dry
    int r = lower_bound(v.begin(), v.end(), 0)-v.begin();
    int l = r-1, discard = 0;
    while(0 <= l && r < 2*n){
        if(v[l]+v[r] < 0)   d++, l--, r++;
        else                l--, discard++;
    }
    d += (l+1+discard)/2;

    // wet
    r = upper_bound(v.begin(), v.end(), 0)-v.begin();
    l = r-1; discard = 0;
    while(0 <= l && r < 2*n){
        if(v[l]+v[r] > 0)   w++, l--, r++;
        else                r++, discard++;
    }
    w += (2*n-1-r+1+discard)/2;

    // moist
    m += z/2;
    for(int i = 1; i < 100001; i++) m += min(plus[i], minus[i]);

    printf("%d %d %d\n", d, w, m);

    return 0;
}