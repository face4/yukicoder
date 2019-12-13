#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

class STlazy{
private:
    int n;
    vector<ll> node, lazy;

public:
    STlazy(vector<ll> v){
        int siz = v.size();
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
        
        for(int i = 0; i < siz; i++)    node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void eval(int k, int l, int r){
        if(lazy[k] == 0)    return;
        node[k] += lazy[k];
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
        node[k] = max(node[2*k+1], node[2*k+2]);
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        eval(k, l, r);
        if(a <= l && r <= b)    return node[k];
        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return max(lx, rx);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> v(n-1);
    for(int i = 0; i < n-1; i++)  cin >> v[i], v[i] += 3*(n-1-i);
    STlazy seg(v);
    int q;
    cin >> q;
    while(q-- > 0){
        int l, r, d;
        cin >> l >> r >> d;
        seg.add(l-1, r, d);
        cout << seg.query(0, n) << endl;
    }
    return 0;
}