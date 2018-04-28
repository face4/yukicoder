#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> points;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x; // useless
        int m, point;
        cin >> m >> point;
        for(int j = 0; j < m; j++){
            string t;
            cin >> t;
            points[t] += point;
        }
    }

    vector<pair<int , string> > ans;
    for(pair<string,int> p : points){
        ans.push_back(make_pair(-p.second, p.first));
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < min(10, (int)ans.size()); i++){
        cout << ans[i].second << " " << -ans[i].first << endl;
    }
    return 0;
}