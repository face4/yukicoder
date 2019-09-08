#include<iostream>
#include<vector>
using namespace std;
const int INF = 1<<30;

struct STmin{
private:
    int n;
    vector<int> dat;
public:
    STmin(vector<int> ini){
        int siz = ini.size();
        n = 1;
        while(n < siz)   n *= 2;
        dat.resize(2*n-1, INF);
        for(int i = 0; i < siz; i++)    dat[n - 1 + i] = ini[i];
        for(int i = n-2; i >= 0; i--)   dat[i] = min(dat[2*i+1], dat[2*i+2]);
    }

    void update(int x, int val){
        x += (n-1);
        dat[x] = val;
        while(x > 0){
            x = (x-1)/2;
            dat[x] = min(dat[2*x+1], dat[2*x+2]);
        }
    }

    // focus on k-th node, who controls [l, r)
    int query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return INF;
        if(a <= l && r <= b)    return dat[k];

        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return min(lx, rx);
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n), rev(n);
    for(int i = 0; i < n; i++)  cin >> a[i], rev[--a[i]] = i;
    STmin seg(a);
    while(q-- > 0){
        int op, l, r;
        cin >> op >> l >> r;
        l--, r--;
        if(op == 1){
            int al = a[l], ar = a[r];
            seg.update(l, ar);
            seg.update(r, al);
            rev[ar] = l; rev[al] = r;
            a[r] = al, a[l] = ar;
        }else{
            int mi = seg.query(l, r+1);
            cout << rev[mi]+1 << endl;
        }
    }
    return 0;
}