#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int indeg[501] = {};
    vector<vector<int>> path(501);

    int g, r, h;
    for(int i = 0; i < m; i++){
        cin >> g >> r;
        indeg[g] = r;
        for(int j = 0; j < r; j++){
            cin >> h;
            path[h].push_back(g);
        }
    }

    queue<int> s;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0)   s.push(i);
    }

    int cnt = 0;
    while(!s.empty()){
        int x = s.front();  s.pop();
        cnt++;
        for(int next : path[x]){
            indeg[next]--;
            if(indeg[next] == 0)    s.push(next);
        }
    }

    cout << cnt << endl;

    return 0;
}