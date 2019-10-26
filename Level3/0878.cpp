// クエリ先読み
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<climits>
#include<set>
using namespace std;

template<typename T>
struct Seg{
private:
    vector<T> node;
    int n;
    function<T(T,T)> f;
    T def;

public:
    Seg(int siz, T d, function<T(T,T)> f) : def(d), f(f) {
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, def);
    }
    Seg(vector<T> v, T d, function<T(T,T)> f) : def(d), f(f){
        n = 1;
        while(n < v.size())  n *= 2;
        node.resize(2*n-1);
        for(int i = 0; i < v.size(); i++)   node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = f(node[2*i+1], node[2*i+2]);
    }

    void update(int x, T val){
        x += n-1;
        node[x] = val; /* ! */
        while(x){
            x = (x-1)/2;
            node[x] = f(node[2*x+1], node[2*x+2]);
        }
    }

    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(b <= l || r <= a)    return def;
        if(a <= l && r <= b)    return node[k];
        T lx = query(a, b, 2*k+1, l, (l+r)/2);
        T rx = query(a, b, 2*k+2, (l+r)/2, r);
        return f(lx, rx);
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    int a[n], rev[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        rev[--a[i]] = i;
    }
    set<int> s; s.insert(-1); s.insert(n);
    vector<pair<int,int>> vp;
    for(int i = n-1; i >= 0; i--){
        auto it = --s.lower_bound(rev[i]);
        vp.push_back({*it+1, rev[i]});
        s.insert(rev[i]);
    }
    vector<pair<int,int>> query(q);
    for(int i = 0; i < q; i++){
        int x, y, z;
        cin >> x >> y >> z;
        vp.push_back({y-1, i+n});
        query[i] = {y-1, z-1};
    }
    sort(vp.begin(), vp.end());
    Seg<int> stsum(n, 0, [](int x, int y){return x+y;});
    vector<int> ans(q);
    for(pair<int,int> p : vp){
        int i = p.first, j = p.second;
        if(j >= n){
            j -= n;
            ans[j] = stsum.query(query[j].first, query[j].second+1);
        }else{
            stsum.update(j, 1);
        }
    }
    for(int i = 0; i < q; i++)  cout << ans[i] << endl;
    return 0;
}