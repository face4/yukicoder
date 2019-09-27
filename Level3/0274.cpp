#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<bool> w(m, 0);
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(m-1-y < x){
            swap(x, y);
            x = m-1-x;
            y = m-1-y;
        }
        vp.push_back({x, y});
    }
    sort(vp.begin(), vp.end());
    for(int i = 0; i < n; i++){
        int l = vp[i].first, r = vp[i].second;
        bool ok = true;
        for(int j = l; j <= r; j++) ok &= !w[j];
        if(ok){
            for(int j = l; j <= r; j++) w[j] = true;
            continue;
        }
        ok = true;
        for(int j = l; j <= r; j++) ok &= !w[m-1-j];
        if(ok){
            for(int j = l; j <= r; j++) w[m-1-j] = true;
            continue;
        }
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}