// 0にくっつけるなら奇数長で短い順->偶数長で長い順(偶数長の最初の01列は1始まりなので)
// 1にくっつけるなら↑の逆が良い(偶数長で短い順->奇数長で長い順)
// 復元の際に、現時点で文字列の末尾が0か1かに応じてappendする01列を変えるために、
// 上の順序付けにおいて最大最小をそれぞれ記録しておく

#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int INF = 1<<30;
const ll LINF = 1ll<<60;

int main(){
    auto f = [](int val)->ll{
        return val%2 == 1 ? val : LINF-val;
    };
    int n;
    cin >> n;
    vector<int> dp(n+1, INF), mi(n+1, INF), ma(n+1, -INF);
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 1; i+j*j <= n; j++){
            if(dp[i+j*j] > dp[i]+j){
                dp[i+j*j] = dp[i]+j;
                mi[i+j*j] = ma[i+j*j] = j;
            }else if(dp[i+j*j] == dp[i]+j){
                if(f(mi[i+j*j]) > f(j)) mi[i+j*j] = j;
                if(f(ma[i+j*j]) < f(j)) ma[i+j*j] = j;
            }
        }
    }
    int out = 0;
    while(n){
        int take;
        if(out == 0)    take = mi[n];
        else            take = ma[n];
        n -= take*take;
        while(take-- > 0){
            cout << out;
            out ^= 1;
        }
        out ^= 1;
    }
    cout << endl;
    return 0;
}