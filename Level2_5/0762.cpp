#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int mod = 1e9+7;

int main(){
    int n, m;
    string s;
    
    cin >> n >> m >> s;

    // convert to 1-indexed
    s = "X"+s;

    vector<int> path[n+1];
    
    int u, v;
    while(m-- > 0){
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    int cnt[n+1];
    
    for(int i = 1; i <= n; i++) cnt[i] = (s[i] == 'P');

    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++){
            if(s[j] != "PDCA"[i])   continue;
            for(int next : path[j]){
                if(s[next] == "PDCA"[i+1])  cnt[next] = (cnt[next]+cnt[j])%mod;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'A') ans = (ans + cnt[i])%mod;
    }

    cout << ans << endl;

    return 0;
}