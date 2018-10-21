#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;

struct Edge{
    int from , to, cost;
    Edge() {}
    Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
    bool operator<(const Edge other) const{
        return cost < other.cost;
    }
};

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

int main(){
    int n, m, k, a, b, c, e;

    cin >> n >> m >> k;

    vector<Edge> v;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--, b--;
        v.push_back(Edge(a, b, c));
    }

    set<int> save;
    for(int i = 0; i < k; i++){
        cin >> e;
        e--;
        save.insert(e);
    }

    DisjointSet uf(n);

    vector<Edge> mst;
    for(int i = 0; i < m; i++){
        if(save.count(i) == 0)  mst.push_back(v[i]);
        else                    uf.unite(v[i].from, v[i].to);
    }

    sort(mst.begin(), mst.end());

    ll ans = 0;
    for(int i = 0; i < mst.size(); i++){
        if(!uf.same(mst[i].from, mst[i].to)){
            uf.unite(mst[i].from, mst[i].to);
        }else{
            ans += mst[i].cost;
        }
    }

    cout << ans << endl;

    return 0;
}