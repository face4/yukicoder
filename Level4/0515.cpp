#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// indexではなく実値を返す
template<class T, class F>
struct SparseTable{
    vector<vector<T>> table;
    vector<int> log_table;
    F f;
    SparseTable(const vector<T> &v, F ff):f(ff){
        int n = v.size();
        int bit = 0;
        while((1<<bit) <= n)    bit++;
        table.resize(bit);
        table[0] = v;
        for(int k = 1; k < bit; k++){
            table[k].resize(n-(1<<k)+1);    // メモリ節約
            for(int i = 0; i+(1<<k) <= n; i++){
                table[k][i] = f(table[k-1][i], table[k-1][i+(1<<(k-1))]);
            }
        }
        log_table.resize(n+1);
        for(int i = 2; i <= n; i++) log_table[i] = log_table[i>>1]+1;
    }

    // 0-indexed, [a, b]
    T query(int a, int b){
        int d = b-a+1;
        int k = log_table[d];
        return f(table[k][a], table[k][b-(1<<k)+1]);
    }
};

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<string,int>> vp;
    for(int i = 0; i < n; i++){
        string s;   cin >> s;
        vp.push_back({s, i});
    }
    sort(vp.begin(), vp.end());
    vector<int> rev(n);
    for(int i = 0; i < n; i++){
        rev[vp[i].second] = i;
    }
    vector<int> v;
    for(int i = 1; i < n; i++){
        int cnt = 0, len = min(vp[i-1].first.length(), vp[i].first.length());
        while(cnt < len && vp[i-1].first[cnt]==vp[i].first[cnt])    cnt++;
        v.push_back(cnt);
    }
    auto f = [](int i, int j){return min(i, j);};
    SparseTable<int,decltype(f)> table(v, f);
    int m;
    ll x, d;
    cin >> m >> x >> d;
    ll ans = 0;
    for(int loop = 0; loop < m; loop++){
        ll i = x/(n-1);
        ll j = x%(n-1);
        if(i > j)   swap(i, j);
        else        j++;
        if(rev[i] > rev[j]) swap(i, j);
        ans += table.query(rev[i], rev[j]-1);
        x = (x+d)%(n*(n-1));
    }
    cout << ans << endl;
    return 0;
}