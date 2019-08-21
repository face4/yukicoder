#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<queue>
using namespace std;
typedef long long ll;

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

    void unite(int x, int y){
        x = parent(x), y = parent(y);
        p[x] = y;
    }
};

// すげえ
int main(){
    int n;
    cin >> n;
    vector<ll> c(n), d(n);
    for(int i = 0; i < n; i++)  cin >> c[i] >> d[i];
    ll ans = accumulate(c.begin(), c.end(), 0ll);
    UF uf(n+1);
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i = 0; i < n; i++){
        if(i)   pq.push({-d[i], {i-1, i}});
        pq.push({-c[i], {n, i}});
    }
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        int i = p.second.first, j = p.second.second;
        if(uf.parent(i) != uf.parent(j)){
            uf.unite(i, j);
            ans += -p.first;
        }
    }
    cout << ans << endl;
    return 0;
}