#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef long long ll;

struct BIT{
    vector<int> v;
    int n;

    BIT(int _n):
        v(vector<int>(_n+1, 0)), n(_n) {}

    int sum(int i){
        int s = 0;
        while(i > 0){
            s += v[i];
            i -= lsb(i);
        }
        return s;
    }
    
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }

    void add(int i, int x){
        while(i <= n){
            v[i] += x;
            i += lsb(i);
        }
    }

private:
    // least significant bit
    int lsb(int i){
        return i & -i;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    ll a[n], b[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    memset(b, 0, sizeof(b));
    char op[q];
    ll x[q], y[q];
    for(int i = 0; i < q; i++){
        cin >> op[i] >> x[i] >> y[i];
        x[i]--;
        if(op[i] == 'B'){
            y[i]--;
        }
    }
    BIT bit(n+1);
    for(int i = q-1; i >= 0; i--){
        if(op[i] == 'A'){
            b[x[i]] += y[i]*bit.sum(x[i]+1);
        }else if(op[i] == 'B'){
            bit.add(x[i]+1, 1);
            bit.add(y[i]+2,-1);
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i]*bit.sum(i+1)+b[i] << " \n"[i==n-1];
    }
    return 0;
}