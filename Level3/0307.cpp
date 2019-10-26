#include<iostream>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;
    int mat[h][w], num = 0;
    for(int i = 0; i < h*w; i++)    cin >> mat[i/w][i%w], num += mat[i/w][i%w];
    int q, all = -1;
    cin >> q;
    while(q-- > 0){
        int r, c, x;
        cin >> r >> c >> x;
        r--, c--;
        if(num == 0 || num == h*w){
            all = x;
            continue;
        }else if(mat[r][c] == x){
            continue;
        }
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            int i = p.first, j = p.second;
            if(mat[i][j] == x)  continue;
            mat[i][j] = x;
            if(x == 0)  num--;
            else        num++;
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]!=x){
                    q.push({ni,nj});
                }
            }
        }
    }
    if(all != -1){
        for(int i = 0; i < h*w; i++)    mat[i/w][i%w] = all;
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << mat[i][j] << " \n"[j==w-1];
        }
    }
    return 0;
}