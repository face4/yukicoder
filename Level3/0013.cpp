#include<iostream>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)

int w, h;
int mat[100][100] = {};
bool visit[100][100] = {};
bool tmpans;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool dfs(int bi, int bj, int i, int j){
    visit[i][j] = true;
    for(int k = 0; k < 4; k++){
        int ni = i + dx[k], nj = j + dy[k];
        if(ni == bi && nj == bj)    continue;
        if(inRange(ni,0,h) && inRange(nj,0,w) && mat[ni][nj] == mat[i][j]){
            if(visit[ni][nj]){
                // 閉路完成
                return true;
            }
            if(dfs(i,j,ni,nj))  return true;
        }
    }
    return false;
}

int main(){
    cin >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(visit[i][j]) continue;
            if(dfs(-1,-1,i,j)){
                cout << "possible" << endl;
                return 0;
            }
        }
    }

    cout << "impossible" << endl;
    
    return 0;
}