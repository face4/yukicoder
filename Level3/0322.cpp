#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<double, int>> v;
    vector<double> t(n), d(n);
    for(int i = 0; i < n; i++)  cin >> t[i];
    for(int i = 0; i < n; i++)  cin >> d[i];
    for(int i = 0; i < n; i++)  v.push_back({t[i]/d[i], i+1});
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; i++)  cout << v[i].second << " \n"[i == n-1];
    return 0;
}