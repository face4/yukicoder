#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

typedef long long ll;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    int row = n, col = n;
    char a[q];
    int b[q], c[q];
    for(int i = 0; i < q; i++)  cin >> a[i] >> b[i] >> c[i];
    vector<ll> ans(k, 0);
    vector<bool> rowb(n, 0), colb(n, 0);
    for(int i = q-1; i >= 0; i--){
        if(a[i] == 'R'){
            if(rowb[b[i]-1])    continue;
            rowb[b[i]-1] = true;
            ans[c[i]-1] += col;
            row--;
        }else if(a[i] == 'C'){
            if(colb[b[i]-1])    continue;
            colb[b[i]-1] = true;
            ans[c[i]-1] += row;
            col--;
        }
    }
    ans[0] += (ll)n*n - accumulate(ans.begin(), ans.end(), 0ll);
    for(int i = 0; i < k; i++)  cout << ans[i] << endl;
    return 0;
}