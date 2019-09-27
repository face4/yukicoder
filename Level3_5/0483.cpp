#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    vector<pair<pii,pii>> vp;
    map<pii, vector<int>> con;
    bool there[101][101] = {};
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        there[a][b] = there[c][d] = true;
        vp.push_back({{a,b},{c,d}});
        con[{a,b}].push_back(i);
        con[{c,d}].push_back(i);
    }
    auto f = [&](int id, pair<int,int> p)->pair<int,int>{
        if(vp[id].first == p)    return vp[id].second;
        return vp[id].first;
    };
    bool valid = true;
    bool visit[101][101] = {};
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 101; j++){
            if(!there[i][j] || visit[i][j]) continue;
            set<pii> dots;
            set<int> match;
            queue<pii> q;
            q.push({i,j});
            visit[i][j] = true;
            while(!q.empty()){
                pii now = q.front();    q.pop();
                dots.insert(now);
                for(int id : con[now]){
                    match.insert(id);
                    pii next = f(id, now);
                    if(visit[next.first][next.second])  continue;
                    visit[next.first][next.second] = true;
                    q.push(next);
                }
            }
            valid &= dots.size() >= match.size();
        }
    }
    cout << (valid ? "YES" : "NO") << endl;
    return 0;
}