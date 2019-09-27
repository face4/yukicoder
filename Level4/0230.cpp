#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

class STlazy{
private:
    int n;
    vector<ll> node, lazy;

public:
    STlazy(int siz){
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, -1);
    }

    void eval(int k, int l, int r){
        if(lazy[k] == -1)    return;
        node[k] = (r-l)*lazy[k]; // ここ!
        if(r-l > 1){
            lazy[2*k+1] = lazy[k];
            lazy[2*k+2] = lazy[k];
        }
        lazy[k] = -1;
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, l, r);
        if(r <= a || b <= l)    return;
        if(a <= l && r <= b){
            lazy[k] = x;
            eval(k, l, r);
            return;
        }
        add(a, b, x, 2*k+1, l, (l+r)/2);
        add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2]; // 自分の全ての子孫の値伝播が終わったら自分を更新する
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        eval(k, l, r); // 最初の呼び出しが必ずeval(0,0,n)となるので漏れなく上から値の伝播がなされている
        if(a <= l && r <= b)    return node[k];
        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    STlazy sega(n), segb(n);
    ll a = 0, b = 0;
    while(q-- > 0){
        int x, l, r;
        cin >> x >> l >> r;
        if(x == 0){
            ll tmpx = sega.query(l, r+1);
            ll tmpy = segb.query(l, r+1);
            if(tmpx > tmpy)         a += tmpx;
            else if(tmpx < tmpy)    b += tmpy;
        }else if(x == 1){
            sega.add(l, r+1, 1);
            segb.add(l, r+1, 0);           
        }else if(x == 2){
            sega.add(l, r+1, 0);
            segb.add(l, r+1, 1);
        }
    }
    cout << a+sega.query(0,n) << " " << b+segb.query(0,n) << endl;
    return 0;
}
