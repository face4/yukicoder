#include<iostream>
#include<vector>
#include<map>
using namespace std;

// 簡易UF
struct UF{
    vector<int> p;
    int n;

    UF(int siz){
        n = siz;
        p.resize(n, 0);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    int parent(int x){
        if(p[x] != x)   p[x] = parent(p[x]);
        return p[x];
    }

    bool same(int x, int y){
        return parent(x) == parent(y);
    }
    
    void unite(int x, int y){
        x = parent(x), y = parent(y);
        p[x] = y;
    }
};

// ナップサックで同じものをN個まで選べるときに
// 2進数を使ってlog(N)で0~N個選ぶ場合を網羅するテク
int main(){
    int n, x;
    cin >> n >> x;
    UF uf(n);
    while(x-- > 0){
        int u, v;
        cin >> u >> v;
        uf.unite(--u, --v);
    }
    vector<int> cnt(n, 0);
    for(int i = 0; i < n; i++)  cnt[uf.parent(i)]++;
    map<int,int> m;
    for(int i = 0; i < n; i++){
        if(cnt[i])  m[cnt[i]]++;
    }
    vector<int> dp(n+1, 1<<30);
    dp[0] = 0;
    for(auto p : m){
        int res = p.second;
        for(int k = 0; res > 0; k++){
            int take = min(1<<k, res);
            res -= take;
            for(int j = n; j >= p.first*take; j--){
                dp[j] = min(dp[j], dp[j-p.first*take]+take);
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << (dp[i]==1<<30 ? -1 : dp[i]-1) << endl;
    return 0;
}