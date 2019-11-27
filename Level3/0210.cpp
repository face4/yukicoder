// 難しい
#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n], q[n];
    for(int i = 0; i < n; i++)  cin >> p[i];
    for(int i = 0; i < n; i++)  cin >> q[i];
    double ans = 0;
    priority_queue<pair<double,int>> pq;
    for(int i = 0; i < n; i++)  pq.push({p[i]/1000.0*q[i]/100.0, i});
    int now = 0;
    while(++now){
        auto p = pq.top();  pq.pop();
        ans += now*p.first;
        if(now*p.first < 1e-6)  break;
        pq.push({p.first*(100-q[p.second])/100.0, p.second});
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}