#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v[n];
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> visit(n, 0);
    int i;
    for(i = 0;;i++) if(v[i].size() == 1)    break;
    queue<int> q;
    q.push(i);
    int ans = 0;
    while(!q.empty()){
        int x = q.front();  q.pop();
        if(visit[x])    continue;
        visit[x] = true;
        if(v[x].size() > 2){
            ans += v[x].size()-2;
        }
        for(int next : v[x]){
            if(!visit[next])    q.push(next);
        }
    }
    cout << ans << endl;
    return 0;
}