#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<double,int>> v;
    int a[n], b[n];
    
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        v.push_back({(double)(a[i])/b[i], i});
    }

    sort(v.rbegin(), v.rend());

    for(pair<double,int> p : v) cout << a[p.second] << " " << b[p.second] << endl;

    return 0;
}