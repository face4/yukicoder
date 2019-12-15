#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};
#define inRange(x,a,b) (a <= x && x < b)

int yoko[1001][1001] = {}, tate[1001][1001] = {}, dp[1001][1001];

void no(){
    cout << "Odekakedekinai.." << endl;
    exit(0);
}

int main(){
    int w, h, n;
    cin >> w >> h >> n;
    while(n--){
        int m;  cin >> m;
        int x;  cin >> x;
        while(m--){
            int y;  cin >> y;
            int i = x/w, j = x%w, ni = y/w, nj = y%w;
            if(i == ni){
                if(j > nj)  swap(j, nj);
                yoko[i][j]++;
                yoko[i][nj]--;
            }else if(j == nj){
                if(i > ni)  swap(i, ni);
                tate[i][j]++;
                tate[ni][j]--;
            }
            x = y;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 1; j < w; j++){
            yoko[i][j] += yoko[i][j-1];
        }
    }
    for(int j = 0; j < w; j++){
        for(int i = 1; i < h; i++){
            tate[i][j] += tate[i-1][j];
        }
    }
    // :(
    if(h==1&&w==1){
        cout << 0 << endl;
        return 0;
    }
    if(tate[0][0]==0&&yoko[0][0]==0){
        no();
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front();  q.pop();
        int i = x/w, j = x%w;
        if(i != 0 && dp[i-1][j] > dp[i][j]+1 && tate[i-1][j]>0){
            dp[i-1][j] = dp[i][j]+1;
            q.push((i-1)*w+j);
        }
        if(i != h-1 && dp[i+1][j] > dp[i][j]+1 && tate[i][j]>0){
            dp[i+1][j] = dp[i][j]+1;
            q.push((i+1)*w+j);
        }
        if(j != 0 && dp[i][j-1] > dp[i][j]+1 && yoko[i][j-1]>0){
            dp[i][j-1] = dp[i][j]+1;
            q.push(i*w+(j-1));
        }
        if(j != w-1 && dp[i][j+1] > dp[i][j]+1 && yoko[i][j]>0){
            dp[i][j+1] = dp[i][j]+1;
            q.push(i*w+(j+1));
        }
    }
    if(dp[h-1][w-1]>1e9)    no();
    else                    cout << dp[h-1][w-1] << endl;
    return 0;
}