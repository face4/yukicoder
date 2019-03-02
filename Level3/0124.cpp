#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

struct data{
    int ti, tj, dir, cost;
};

bool isK(int a, int b, int c){
    return a!=b && b!=c && c!=a && (b-a)*(b-c)>0;
}

int main(){
    int w, h;
    cin >> w >> h;

    int mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    int dp[h][w][4];
    for(int i = 0; i < h; i++)  for(int j = 0; j < w; j++)  for(int k = 0; k < 4; k++)  dp[i][j][k] = 1<<30;

    queue<data> q;
    if(mat[0][0] != mat[0][1])  q.push(data({0, 1, 0, 1}));
    if(mat[0][0] != mat[1][0])  q.push(data({1, 0, 2, 1}));

    while(!q.empty()){
        data p = q.front(); q.pop();
        int i = p.ti, j = p.tj, d = p.dir, c = p.cost;
        int pi = i-di[d], pj = j-dj[d];
        if(dp[i][j][d] <= c)    continue;
        dp[i][j][d] = c;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k], nj = j+dj[k];
            if(!inRange(ni, 0, h) || !inRange(nj, 0, w))    continue;
            if(isK(mat[pi][pj], mat[i][j], mat[ni][nj]) && dp[ni][nj][k] > c+1){
                q.push(data({ni, nj, k, c+1}));
            }
        }
    }

    int ans = 1<<30;
    for(int i = 0; i < 4; i++)  ans = min(ans, dp[h-1][w-1][i]);
    cout << (ans == 1<<30 ? -1 : ans) << endl;

    return 0;
}