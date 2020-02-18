/*
    爆破した橋を復元することができる!!!
    (ずっと復元出来ないと思っていた)
*/

#include<iostream>
#include<vector>
#include<set>
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

int main(){
    int n;
    cin >> n;
    UF uf(n);
    vector<int> deg(n, 0);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
        uf.unite(u, v);
    }
    set<int> s;
    for(int i = 0; i < n; i++)  s.insert(uf.parent(i));
    int comp = s.size();
    bool able = false;
    for(int i = 0; i < n; i++)  able |= deg[i]==1;
    if(able)    comp++;
    comp--;
    cout << (comp == 1 ? "Bob" : "Alice") << endl;
    return 0;
}