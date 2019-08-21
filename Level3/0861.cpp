#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;

#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

ll c[5][5];
bool f[5][5] = {}, memo[1<<25] = {};
ll sum = 0, ans = 1ll<<60;

void dfs(int val, ll acc){
    memo[val] = true;
    ans = min(ans, abs(sum-acc-acc));

    for(int x = 0; x < 25; x++){
        int i = x/5, j = x%5;
        if(f[i][j] || memo[val+(1<<x)] || val+(1<<x)==(1<<25)-1) continue;
        bool ok = false;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k], nj = j+dj[k];
            if(inRange(ni,0,5)&&inRange(nj,0,5)&&f[ni][nj]) ok = true;
        }
        if(!ok) continue;

        f[i][j] = true;
        
        queue<int> q;
        bool tmp[5][5] = {};
        bool flag = true;
        for(int ii = 0; ii < 5; ii++){
            for(int jj = 0; jj < 5; jj++){
                if(f[ii][jj]) continue;
                tmp[ii][jj] = true;
                q.push(ii*5+jj);
                flag = false;
                break;
            }
            if(!flag)   break;
        }
        int dual = 0;
        while(!q.empty()){
            int p = q.front(); q.pop();
            int ii = p/5, jj = p%5;
            dual += 1<<p;
            for(int k = 0; k < 4; k++){
                int ni = ii+di[k], nj = jj+dj[k];
                if(inRange(ni,0,5)&&inRange(nj,0,5)&&!tmp[ni][nj]&&!f[ni][nj]){
                    tmp[ni][nj] = true;
                    q.push(ni*5+nj);
                }
            }
        }

        if(dual + val + (1<<x) == (1<<25)-1){
            dfs(val+(1<<x), acc+c[i][j]);
        }
        f[i][j] = false;
    }
}

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> c[i][j];
            sum += c[i][j];
        }
    }
    f[0][0] = true;
    dfs(1, c[0][0]);
    cout << ans << endl;
    return 0;
}