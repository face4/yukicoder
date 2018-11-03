#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n;
    cin >> n;

    int INF = 100001;
    vector<vector<int>> v(n+1);
    vector<int> r(n+1, INF), l(n+1, INF);
    vector<int> deg(n+1, 0);

    int x, y;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    stack<pair<int,int>> s;
    s.push({1, 0});
    while(!s.empty()){
        pair<int,int> p = s.top();  s.pop();
        r[p.first] = p.second;
        for(int next : v[p.first]){
            if(r[next] != INF)  continue;
            s.push({next, p.second+1});
        }
    }

    for(int i = 2; i <= n; i++){
        if(deg[i] != 1)  continue;
        s.push({i, 0});
        while(!s.empty()){
            pair<int,int> now = s.top();    s.pop();
            if(now.second >= l[now.first])  continue;
            l[now.first] = now.second;
            for(int next : v[now.first]){
                if(now.second + 1 < l[next]){
                    s.push({next, now.second + 1});
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) printf("%d\n", min(l[i], r[i]));

    return 0;
}
