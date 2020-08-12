#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  scanf("%d", a.begin()+i), a[i] -= x;
    for(int i = 0; i < n; i++)  scanf("%d", b.begin()+i);
    int k = -accumulate(a.begin(), a.end(), 0);
    if(*max_element(a.begin(),a.end()) < 0){
        cout << -1 << endl;
        return 0;
    }else if(k <= 0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> dp(k+100, 1<<30);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= 0)   continue;
        for(int j = k+99; j >= -a[i]; j--){
            dp[j] = min(dp[j], dp[j+a[i]]+b[i]);
        }
    }
    printf("%d\n", *min_element(dp.begin()+k, dp.end()));
    return 0;
}