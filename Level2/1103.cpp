#include<iostream>
#include<vector>
using namespace std;

vector<int> v[1000001];
vector<int> ans, des, indeg;

void dfs(int p, int x){
    ans[x] = ans[p]+1;
    des[x] = 1;
    for(int child : v[x]){
        dfs(x, child);
        des[x] += des[child];
    }
}

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ans.resize(n+1, 0);
    des.resize(n+1, 0);
    indeg.resize(n+1, 0);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        indeg[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(indeg[i])    continue;
        dfs(0, i);
        break;
    }
    ll ret = 0;
    const ll mod = 1000000007;
    for(int i = 1; i <= n; i++){
        for(int j : v[i]){
            ret += (ll)ans[i]*des[j]%mod;
            ret %= mod;
        }
    }
    cout << ret << endl;
    return 0;
}