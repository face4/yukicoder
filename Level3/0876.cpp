#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

struct BIT{
    int n;
    vector<int> dat;
    BIT(int siz){
        n = siz;
        dat.resize(n+1, 0);
    }

    void add(int i, int x){
        while(i <= n){
            dat[i] += x;
            i += i&-i;
        }
    }

    int sum(int i){
        int ret = 0;
        while(i > 0){
            ret += dat[i];
            i -= i&-i;
        }
        return ret;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<ll> b(n);
    b[0] = 0;
    for(int i = 1; i < n; i++)  b[i] = a[i]-a[i-1];
    BIT bit(n);
    for(int i = 1; i < n; i++)  if(b[i])   bit.add(i, 1);
    while(q-- > 0){
        int op;
        cin >> op;
        if(op == 2){
            int l, r;
            cin >> l >> r;
            cout << bit.sum(r-1)-bit.sum(l-1)+1 << endl;
        }else{
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            if(l > 0 && b[l] != 0)  bit.add(l, -1);
            b[l] += x;
            if(l > 0 && b[l] != 0)  bit.add(l, 1);
            if(r+1 < n && b[r+1] != 0)    bit.add(r+1, -1);
            if(r+1 < n) b[r+1] -= x;
            if(r+1 < n && b[r+1] != 0)    bit.add(r+1, 1);
        }
        // for(int i = 0; i < n; i++)  cout << b[i] << " \n"[i+1==n];
        // for(int i = 0; i <= n; i++)  cout << bit.sum(i) << " \n"[i==n];
    }
    return 0;
}