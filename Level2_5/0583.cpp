// domino?
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int s[500] = {};
vector<vector<int>> train(500);
bool visit[500] = {};
set<int> stations;

int main(){
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        s[a]++;
        s[b]++;
        train[a].push_back(b);
        train[b].push_back(a);
        stations.insert(a);
        stations.insert(b);
    }

    // 全ての列車にちょうど1回ずつ乗れるかどうかの判定
    int odd = 0;
    for(int i = 0; i < n; i++){
        odd += (s[i] % 2);
    }

    bool rule1 = (odd == 0 || odd == 2);

    // 連結判定
    int cnt = 0;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(visit[now])  continue;

        visit[now] = true;
        cnt++;

        for(int x : train[now]) if(!visit[x])   q.push(x);
    }

    bool rule2 = (cnt == stations.size());

    if(rule1 && rule2)  cout << "YES" << endl;
    else                cout << "NO" << endl;

    return 0;
}