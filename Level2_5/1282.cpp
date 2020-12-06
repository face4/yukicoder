#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct BIT{
    // 1-origin
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

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)  cin >> b[i];
    vector<int> x;
    for(int i = 0; i < n; i++)  x.push_back(a[i]), x.push_back(b[i]);
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    int m = x.size();
    BIT bit(m);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        bit.add(lower_bound(x.begin(), x.end(), b[i])-x.begin()+1, 1);
        ans += bit.sum(lower_bound(x.begin(), x.end(), a[i])-x.begin());
    }
    cout << ans << endl;
    return 0;
}