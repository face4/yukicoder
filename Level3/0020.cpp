// グリッド上でdijkstra
#include<iostream>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

const int INF = 1<<25;
int n, v, x, y, mat[200][200], dist[200][200];

void dijk(int fi, int fj){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = INF;
        }
    }
    dist[fi][fj] = 0;

    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({-dist[fi][fj],{fi,fj}});

    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        int c = -p.first, i = p.second.first, j = p.second.second;
        if(c > dist[i][j]) continue;
        
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(!inRange(ni,0,n) || !inRange(nj,0,n))    continue;
            if(dist[ni][nj] > mat[ni][nj] + c){
                dist[ni][nj] = mat[ni][nj] + c;
                pq.push({-dist[ni][nj], {ni,nj}});
            }
        }
    }
}

int main(){
    cin >> n >> v >> x >> y;
    x--; y--;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    
    dijk(0,0);

    bool judge = false;
    if(dist[n-1][n-1] < v)  judge = true;

    if(x+y != -2){
        dijk(y,x);
        // -mat[y][x]+mat[0][0]に気付くまでが本当に時間がかかった
        if((v-dist[0][0]-mat[y][x]+mat[0][0])*2-dist[n-1][n-1] > 0) judge = true;
    }

    if(judge) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}