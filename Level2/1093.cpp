#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> v[i], v[i] += v[i-1];
    vector<int> s;
    for(int i = k; i <= n; i++) s.push_back(v[i]-v[i-k]);
    sort(s.begin(), s.end());
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << upper_bound(s.begin(), s.end(), x)-s.begin() << endl;
    }
    return 0;
}