#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int n, m;
    cin >> n >> m;
    int fee[n][n];
    memset(fee, 0, sizeof(fee));
    ll dp[2][n][n];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        fee[--x][--y] = z;
    }
    priority_queue<pair<ll,pii>> pq;
    pq.push({-0, {0, 0}});
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        ll c = -p.first;
        int x = p.second.first, i = p.second.second/n, j = p.second.second%n;
        if(dp[x][i][j] != c)    continue;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k], nj = j+dj[k];
            if(!inRange(ni,0,n)||!inRange(nj,0,n))  continue;
            ll nc = c+1+fee[ni][nj];
            if(dp[x][ni][nj] > nc){
                dp[x][ni][nj] = nc;
                pq.push({-nc, {x, ni*n+nj}});
            }
            if(x)   continue;
            nc -= fee[ni][nj];
            if(dp[1][ni][nj] > nc){
                dp[1][ni][nj] = nc;
                pq.push({-nc, {1, ni*n+nj}});
            }
        }
    }
    cout << dp[1][n-1][n-1] << endl;
    return 0;
}