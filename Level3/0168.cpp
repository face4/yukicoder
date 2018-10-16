#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

class DisjointSet{
  public:
    vector<int> rank, p;

    DisjointSet(){}
    DisjointSet(int size){
        rank.resize(size, 0);
        p.resize(size, 0);
        for(int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x){
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }
    
    void unite(int x, int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if(rank[x] > rank[y]){
            p[y] = x;
        }else{
            p[x] = y;
            if(rank[x] == rank[y]){
                rank[y]++;
            }
        }
    }

    int findSet(int x){
        if(x != p[x]){
            // path compression
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll x[n], y[n];
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];

    priority_queue<pair<ll, pair<int,int>>> pq;
    DisjointSet uf(n);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            pq.push({-((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])), {i, j}});
        }
    }

    ll sq = 0;
    while(!uf.same(0, n-1)){
        auto p = pq.top();  pq.pop();
        sq = -p.first;
        uf.unite(p.second.first, p.second.second);
    }

    ll ans = (ll)(sqrt(sq))/10*10;
    while(ans*ans < sq) ans += 10;

    cout << ans << endl;

    return 0;
}