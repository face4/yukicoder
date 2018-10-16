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


int main(){
    int n, m, a, b;
    cin >> n >> m;

    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a > b)   swap(a, b);
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    BIT bit(m);

    long long ans = 0;
    for(pair<int,int> p : v){
        a = p.first+1, b = p.second+1;
        ans += bit.sum(a, b);
        bit.add(b, +1);
    }

    cout << ans << endl;

    return 0;
}

