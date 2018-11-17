#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

// rankを考慮しない簡易版のuf
struct UnionFind{
    vector<int> p;
    UnionFind(int n){
        p.resize(n);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    int findSet(int x){
        if(x != p[x])   p[x] = findSet(p[x]);
        return p[x];
    }

    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }

    void unite(int x, int y){
        int px = findSet(x), py = findSet(y);
        p[px] = py;
    }
};

int main(){
    int n;
    cin >> n;

    UnionFind uf(n);
    int x[n], y[n];
    
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= 100)  uf.unite(i,j);
        }
    }

    double ans = 1 + (n != 0);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(!uf.same(i, j))  continue;
            ans = max(ans, sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) + 2);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}