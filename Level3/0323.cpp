#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w, a, si, sj, b, gi, gj;
    cin >> h >> w >> a >> si >> sj >> b >> gi >> gj;
    char mat[h][w];
    for(int i = 0; i < h*w; i++)    cin >> mat[i/w][i%w];
    bool dp[h][w][3500+1];
    memset(dp, 0, sizeof(dp));
    queue<pair<int,pair<int,int>>> q;
    q.push({a, {si,sj}});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int i = p.second.first, j = p.second.second, c = p.first;
        if(dp[i][j][c]) continue;
        dp[i][j][c] = true;
        if(c == 0)  continue;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k], nj = j+dj[k];
            if(!inRange(ni,0,h) || !inRange(nj,0,w) || c+(mat[ni][nj]=='*'?1:-1) > 3500 || dp[ni][nj][c+(mat[ni][nj]=='*'?1:-1)]){
                continue;
            }
            q.push({c+(mat[ni][nj]=='*'?1:-1), {ni,nj}});
        }
    }
    cout << (dp[gi][gj][b]?"Yes":"No") << endl;
    return 0;
}