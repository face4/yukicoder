#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ull seed;
int next() {
    seed = seed ^ (seed << 13);
    seed = seed ^ (seed >> 7);
    seed = seed ^ (seed << 17);
    return (seed >> 33);
}

int len = (1ll<<31)/(200000)+1;
vector<int> block[200001];
vector<int> cnt(200001, 0);

int main() {
    int n, q;
    cin >> n >> q >> seed;
    for (int i = 0; i < 10000; i++) next();
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = next();
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        block[a[i]/len].push_back(a[i]);
        cnt[a[i]/len]++;
    }
    for(int i = 1; i < 200001; i++) cnt[i] += cnt[i-1];
    ll sum = 0;
    for(int i = 0; i < q; i++){
        int x = next();
        int pos = x/len;
        int tmp = pos==0 ? 0 : cnt[pos-1];
        for(int j : block[pos]){
            if(j < x)   tmp++;
            else        break;
        }
        sum ^= (ll)tmp * i;
    }
    cout << sum << endl;
    return 0;
}