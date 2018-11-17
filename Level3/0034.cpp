#include<iostream>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

struct data{
    int i, j, step, cost;
};

int main(){
    int n, v, si, sj, gi, gj;
    cin >> n >> v >> sj >> si >> gj >> gi;
    si--, sj--, gi--, gj--;

    int l[n][n], d[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> l[i][j];
            d[i][j] = 1<<21;
        }
    }

    queue<data> q;

    q.push(data({si, sj, 0, 0}));

    while(!q.empty()){
        data da = q.front();  q.pop();
        if(da.i == gi && da.j == gj){
            cout << da.step << endl;
            return 0;
        }

        if(da.cost >= d[da.i][da.j])    continue;

        d[da.i][da.j] = da.cost;

        for(int k = 0; k < 4; k++){
            int ni = da.i + dx[k], nj = da.j + dy[k];
            if(!inRange(ni, 0, n) || !inRange(nj, 0, n) || da.cost + l[ni][nj] >= min(d[ni][nj], v)) continue;
            q.push(data({ni, nj, da.step+1, da.cost+l[ni][nj]}));
        }
    }

    cout << -1 << endl;

    return 0;
}