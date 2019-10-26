#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int asum = 0, bsum = 0;
    vector<int> a(n-1), b(n-1);
    for(int i = 0; i < n-1; i++){
        cin >> a[i] >> b[i];
        asum += a[i], bsum += b[i];
    }
    int ans = 0;
    for(int i = 0; i <= bsum; i++){
        int j = asum+i-bsum;
        if(j < 0)   continue;
        int tmpa = asum+i, tmpb = bsum+j;
        bool valid = true;
        for(int k = 0; k < n-1; k++){
            valid &= a[k] <= tmpb-b[k];
        }
        ans += valid;
    }
    cout << ans << endl;
    return 0;
}