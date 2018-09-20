#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int s[n], p[n], u[n];
    for(int i = 0; i < n; i++)  cin >> s[i] >> p[i] >> u[i];

    vector<pair<pair<int,int>,int>> univ[100010];
    for(int i = 0; i < n; i++){
        univ[u[i]].push_back({{s[i],-p[i]},i});
    }

    priority_queue< pair< pair<int,pair<int,int>>, int> > pq;

    for(int u = 0; u <= 100000; u++){
        if(univ[u].size()){
            sort(univ[u].rbegin(), univ[u].rend());
            for(int i = 0; i < univ[u].size(); i++){
                int x = univ[u][i].second;
                pq.push({{s[x], {-i, -p[x]}},x});
            }
        }
    }

    for(int i = 0; i < k; i++){
        auto p = pq.top();  pq.pop();
        cout << p.second << endl;
    }

    return 0;
}