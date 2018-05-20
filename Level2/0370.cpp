#include<iostream>
#include<algorithm>
using namespace std;

int dis[1000];

int main(){
    int n, m, d;
    cin >> n >> m;

    for(int i = 0; i < m; i++)  cin >> dis[i];

    sort(dis, dis+m);

    int ans = 1<<21;

    for(int i = 0; i <= m-n; i++){
        int l = dis[i];
        int r = dis[i+n-1];
        if(l*r >= 0){
            ans = min(ans, (max(abs(l), abs(r))));
        }else{
            ans = min(ans, 2*min(abs(l), abs(r)) + max(abs(l),abs(r)));
        }
    }

    cout << ans << endl;

    return 0;
}