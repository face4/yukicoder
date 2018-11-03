#include<iostream>
using namespace std;
typedef long long ll;

int sum[1505][1505] = {};

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int x[n], y[n], hp[n];
    for(int i = 0; i < n; i++)  scanf("%d %d %d", x+i, y+i, hp+i);

    int ax, ay, w, h, d;
    for(int i = 0; i < k; i++){
        scanf("%d %d %d %d %d", &ax, &ay, &w, &h, &d);
        ax += 501;
        ay += 501;
        sum[ax][ay] += d;
        sum[ax+w+1][ay] -= d;
        sum[ax][ay+h+1] -= d;
        sum[ax+w+1][ay+h+1] += d;
    }

    for(int i = 1; i < 1505; i++){
        for(int j = 1; j < 1505; j++){
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += max(0, hp[i]-sum[x[i]+501][y[i]+501]);
    }

    cout << ans << endl;

    return 0;
}