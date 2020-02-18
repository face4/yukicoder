#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

class STlazy{
private:
    int n;
    vector<ll> node, lazy;
    vector<int> plus, minus;

public:
    STlazy(vector<int> v, vector<int> p){
        int siz = v.size();
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
        plus.resize(2*n-1, 0);
        minus.resize(2*n-1, 0);
        for(int i = 0; i < siz; i++)    node[n-1+i] = v[i], plus[n-1+i] = p[i], minus[n-1+i] = 1-p[i];
        for(int i = n-2; i >= 0; i--)   node[i] = node[2*i+1] + node[2*i+2], plus[i] = plus[2*i+1]+plus[2*i+2], minus[i] = minus[2*i+1]+minus[2*i+2];
    }

    void eval(int k, int l, int r){
        if(lazy[k] == 0)    return;
        node[k] += lazy[k]*(plus[k]-minus[k]);
        if(r-l > 1){
            lazy[2*k+1] += lazy[k];
            lazy[2*k+2] += lazy[k];
        }
        lazy[k] = 0;
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, l, r);
        if(r <= a || b <= l)    return;
        if(a <= l && r <= b){
            lazy[k] += x;
            eval(k, l, r);
            return;
        }
        add(a, b, x, 2*k+1, l, (l+r)/2);
        add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2];
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        eval(k, l, r);
        if(a <= l && r <= b)    return node[k];
        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

typedef pair<int,int> pii;

int k = 0;
vector<int> etour, pl;
vector<pii> v[100000];
int be[100000], en[100000];

void euler_tour(int x, int p){
    be[x] = k;
    for(pii P : v[x]){
        if(P.first == p)   continue;
        pl.push_back(1);
        etour.push_back(P.second);
        k++;
        euler_tour(P.first, x);
        pl.push_back(0);
        etour.push_back(-P.second);
        k++;
    }
    en[x] = k;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    euler_tour(0, -1);
    STlazy seg(etour, pl);
    int q;
    cin >> q;
    while(q--){
        int op, a, b;
        cin >> op;
        if(op == 1){
            cin >> a >> b;
            seg.add(be[a], en[a], b);
        }else{
            cin >> a;
            cout << seg.query(0, be[a]) << endl;
        }
    }
    return 0;
}