#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    int n, d, k, x;
    cin >> n >> d >> k;

    ll ans = 0;
    int posi, posj;
    priority_queue<pair<int,int>> pq;
    cin >> x;
    pq.push({-x, -0});

    for(int i = 1; i < n; i++){
        cin >> x;
        while(-pq.top().second < i-d) pq.pop();
        if( (ll)(x+pq.top().first)*k > ans){
            ans = (ll)(x+pq.top().first)*k;
            posi = -pq.top().second, posj = i;
        }
        pq.push({-x, -i});
    }

    cout << ans << endl;
    if(ans) cout << posi << " " << posj << endl;

    return 0;
}