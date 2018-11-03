#include<iostream>
#include<queue>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)

struct data{
    // pos-i, pos-j, type(0-knight, 1-bishop), cost
    int i, j, t, c;
};

int dx[2][8] = { {1,1,-1,-1,2,2,-2,-2}, {1,1,-1,-1,0,0,0,0} };
int dy[2][8] = { {2,-2,2,-2,1,-1,1,-1}, {1,-1,1,-1,0,0,0,0} };

int main(){
    int h, w;
    cin >> h >> w;

    char mat[h][w];
    int dp[h][w][2]; // 0-knight, 1-bishop
    int INF = 300000;
    int si, sj, gi, gj;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'S')    si = i, sj = j;
            if(mat[i][j] == 'G')    gi = i, gj = j;
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }

    queue<data> s;
    s.push(data({si, sj, 0, 0}));

    while(!s.empty()){
        data d = s.front();   s.pop();

        // discard
        if(d.c >= dp[d.i][d.j][d.t])    continue;

        // apply
        dp[d.i][d.j][d.t] = d.c;

        // goal
        if(d.i == gi && d.j == gj){
            cout << d.c << endl;
            return 0;
        }

        // metamorphosis
        if(mat[d.i][d.j] == 'R')    d.t = 1 - d.t;

        // move
        for(int k = 0; k < 8; k++){
            int ni = d.i + dx[d.t][k];
            int nj = d.j + dy[d.t][k];

            if(!inRange(ni, 0, h) || !inRange(nj, 0, w))    continue;

            if(d.c + 1 < dp[ni][nj][d.t]){
                s.push(data({ni,nj,d.t,d.c+1}));
            }
        }

    }

    cout << -1 << endl;

    return 0;
}