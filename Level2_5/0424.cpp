#include<iostream>
#include<stack>
using namespace std;

int main(){
    int h, w, sx, sy, gx, gy;
    cin >> h >> w >> sx >> sy >> gx >> gy;

    // convert 1-origin to 0-origin
    sx--; sy--; gx--; gy--;

    int G[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            G[i][j] = 0;
        }
    }
    bool visit[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            visit[i][j] = false;
        }
    }
    string t;
    for(int i = 0; i < h; i++){
        cin >> t;
        for(int j = 0; j < w; j++){
            G[i][j] = t[j]-'0';
        }
    }

    // bfs
    visit[sx][sy] = true;
    stack<pair<int,int>> s;
    s.push({sx,sy});
    while(!s.empty()){
        pair<int,int> p = s.top();  s.pop();
        int x = p.first;
        int y = p.second;
        int z = G[x][y];
        visit[x][y] = true;
        if(x > 1   && !visit[x-2][y] && z > G[x-1][y] && z == G[x-2][y])    s.push({x-2,y});
        if(x < h-2 && !visit[x+2][y] && z > G[x+1][y] && z == G[x+2][y])    s.push({x+2,y});
        if(y > 1   && !visit[x][y-2] && z > G[x][y-1] && z == G[x][y-2])    s.push({x,y-2});
        if(y < w-2 && !visit[x][y+2] && z > G[x][y+1] && z == G[x][y+2])    s.push({x,y+2});
        if(x > 0   && !visit[x-1][y] && abs(G[x][y]-G[x-1][y]) <= 1)        s.push({x-1,y});
        if(x < h-1 && !visit[x+1][y] && abs(G[x][y]-G[x+1][y]) <= 1)        s.push({x+1,y});
        if(y > 0   && !visit[x][y-1] && abs(G[x][y]-G[x][y-1]) <= 1)        s.push({x,y-1});
        if(y < w-1 && !visit[x][y+1] && abs(G[x][y]-G[x][y+1]) <= 1)        s.push({x,y+1});
    }

    if(visit[gx][gy])   cout << "YES" << endl;
    else                cout << "NO" << endl;

    return 0;
}