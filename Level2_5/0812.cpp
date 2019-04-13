#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

struct UF{
    vector<int> p, rank;
    int n;
    UF(int siz){
        n = siz;
        p.resize(n), rank.resize(n, 1);
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
        if(x == y)  return;
        if(rank[x] < rank[y]){
            p[x] = y;
            rank[y] += rank[x];
        }else{
            p[y] = x;
            rank[x] += rank[y];
        }
    }

    int getSize(int x){
        return rank[parent(x)];
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> path[n];
    UF uf(n);
    while(m-- > 0){
        int p, q;
        cin >> p >> q;
        p--, q--;
        uf.unite(p, q);
        path[p].push_back(q);
        path[q].push_back(p);
    }
    int q;
    cin >> q;
    while(q-- > 0){
        int a;
        cin >> a;
        a--;
        vector<bool> visit(n, 0);
        queue<pair<int,int>> q;
        q.push({a, -1});
        int day;
        while(!q.empty()){
            pair<int,int> p = q.front();    q.pop();
            if(visit[p.first])  continue;
            visit[p.first] = true;
            day = p.second;
            for(int next : path[p.first]){
                if(!visit[next])    q.push({next, day+1});
            }
        }
        cout << uf.getSize(a)-1 << " " << (day > 0 ? ceil(log2(day+1)) : 0) << endl;
    }
    return 0;
}