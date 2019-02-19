#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

const int INF = INT_MAX;
typedef long long ll;

int main(){
    int n, m, l;
    cin >> n >> m >> l;
    l--;

    vector<int> t(n);
    for(int i = 0; i < n; i++)  cin >> t[i];
    int cnt = 0;
    for(int i = 0; i < n; i++)  if(t[i])    cnt++;
    if(cnt == 1){
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> v(n, vector<int>(n, INF));
    vector<pair<int,int>> path[n];
    int a, b, c;
    while(m-- > 0){
        cin >> a >> b >> c;
        a--, b--;
        path[a].push_back({c,b});
        path[b].push_back({c,a});
    }

    for(int i = 0; i < n; i++){
        priority_queue<pair<int,int>> pq;
        pq.push({-0, i});
        while(!pq.empty()){
            pair<int,int> now = pq.top();   pq.pop();
            int cost = -now.first, pos = now.second;
            if(cost >= v[i][pos])   continue;
            v[i][pos] = cost;
            for(pair<int,int> p : path[pos]){
                if(cost+p.first < v[i][p.second]){
                    pq.push({-(cost+p.first), p.second});
                }
            }
        }
    }
    
    vector<ll> gather(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            gather[i] += 2 * (ll)v[i][j] * t[j];
        }
    }
    
    ll ans = 1ll<<60;
    for(int s = 0; s < n; s++){
        if(t[s] == 0)   continue;
        for(int g = 0; g < n; g++){
            ans = min(ans, gather[g] + v[l][s] - v[s][g]);
        }
    }

    cout << ans << endl;

    return 0;
}