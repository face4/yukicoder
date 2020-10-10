#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;

// F : T x T -> T
// G : T x E -> T
// H : E x E -> E
// R : E x int(length of the range) -> E
template<typename T, typename E, typename F, typename G, typename H, typename R>
struct SegL{
private:
    vector<T> node;
    vector<E> lazy;
    int n;
    T defVal;
    E defOp;
    F f;    // merge elements(T)
    G g;    // update element(T) 
    H h;    // merge operators(E)
    R r;    // operator depends on length

    void init(int siz, T defVal, E defOp){
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, defVal);
        lazy.resize(2*n-1, defOp);
    }

public:
    SegL(int siz, T defVal, E defOp, F f, G g, H h, R r) : defVal(defVal), defOp(defOp), f(f), g(g), h(h), r(r){
        init(siz, defVal, defOp);
    }
    SegL(vector<T> v, T defVal, E defOp, F f, G g, H h, R r) : defVal(defVal), defOp(defOp), f(f), g(g), h(h), r(r){
        init(v.size(), defVal, defOp);
        for(int i = 0; i < v.size(); i++)   node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = f(node[2*i+1], node[2*i+2]);
    }

    void eval(int k, int len){
        if(lazy[k] == defOp)    return;
        if(k < n-1){
            lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
        }
        node[k] = g(node[k], r(lazy[k], len));
        lazy[k] = defOp;
    }

    void update(int a, int b, E x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, r-l);
        if(b <= l || r <= a){
            return;
        }else if(a <= l && r <= b){
            lazy[k] = h(lazy[k], x);
            eval(k, r-l);
        }else{
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = f(node[2*k+1], node[2*k+2]);
        }
    }

    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, r-l);
        if(b <= l || r <= a)    return defVal;
        if(a <= l && r <= b)    return node[k];
        T lx = query(a, b, 2*k+1, l, (l+r)/2);
        T rx = query(a, b, 2*k+2, (l+r)/2, r);
        return f(lx, rx);
    }
};

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    auto f = [](ll a, ll b)->ll{return min(a,b);};
    auto g = [](ll a, ll b)->ll{return a+b;};
    auto h = [](ll a, ll b)->ll{return a+b;};
    auto r = [](ll a, ll b)->ll{return a;};
    SegL<ll, ll, decltype(f), decltype(g), decltype(h), decltype(r)> seg(v, 1ll<<62, 0, f, g, h, r);
    int q;
    cin >> q;
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        b--;
        if(a == 1){
            seg.update(b, c, d);
        }else{
            cout << seg.query(b, c) << endl;
        }
    }
    return 0;
}