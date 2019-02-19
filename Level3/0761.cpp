#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int n;
vector<ll> a, s;

// 半開区間[l, r)
bool dfs(int l, int r){
    if(r <= l)  return false;
    ll ave = (s[r] - s[l])/(r-l);
    if((s[r]-s[l])%(r-l))   ave++;
    int pivot = lower_bound(a.begin()+l, a.begin()+r, ave) - a.begin();
    if(pivot == l)  return true;
    bool win = !dfs(l, pivot) | !dfs(pivot, r);
    return win;
};

int main(){
    int n;
    cin >> n;
    a.resize(n), s.resize(n+1);
    s[0] = 0;
    for(int i = 0; i < n; i++)  cin >> a[i], s[i+1] = s[i]+a[i];
    cout << (dfs(0, n) ? "First" : "Second") << endl;
    return 0;
}