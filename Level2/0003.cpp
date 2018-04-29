#include<iostream>
#include<queue>
using namespace std;

#define INF 10001;
bool flag[10001];
int cnt[10001];

int bit(int x){
    int res = 0;
    for(; x != 0; x &= x-1){
        res++;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 10001; i++){
        flag[i] = false;
        cnt[i] = INF;
    }

    cnt[1] = 1;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int now = q.front(); q.pop();
        if(flag[now])   continue;
        flag[now] = true;
        int move = bit(now);
        if(now-move >= 1 && !flag[now-move]){
            cnt[now-move] = min(cnt[now-move], cnt[now]+1); //同時に同じ深さの到達点が複数インキューされるので、minが必要
            q.push(now-move);
        }
        if(now+move <= n && !flag[now+move]){
            cnt[now+move] = min(cnt[now+move], cnt[now]+1);
            q.push(now+move);
        }
    }

    if(flag[n]) cout << cnt[n] << endl;
    else        cout << -1 << endl;
    return 0;
}