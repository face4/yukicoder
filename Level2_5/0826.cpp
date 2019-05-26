#include<iostream>
#include<vector>
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

int main(){
    int n, p;
    cin >> n >> p;
    vector<int> prime;
    bool nonp[1000001] = {};
    for(int i = 2; i < 1000001; i++){
        if(nonp[i]) continue;
        prime.push_back(i);
        for(int j = i+i; j < 1000001; j+= i)    nonp[j] = true;
    }
    int pnum = prime.size();
    DisjointSet uf(n);

    // ここが重いかもしれない
    for(int j = 0; j < pnum; j++){
        if(prime[j] > n)    break;
        for(int i = prime[j]+prime[j]; i <= n; i+=prime[j]){
            uf.unite(i-1, i-prime[j]-1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)  if(uf.same(p-1,i))  ans++;
    cout << ans << endl;
    return 0;
}