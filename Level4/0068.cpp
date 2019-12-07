// 面白い
#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;

double pre[500001];

int main(){
    int n;
    cin >> n;
    priority_queue<pair<double,int>> pq;
    for(int i = 0; i < n; i++){
        int x;  cin>> x;
        pq.push({x, 1});
    }
    for(int i = 1; i <= 500000; i++){
        pair<double,int> p = pq.top();  pq.pop();
        pre[i] = p.first;
        pq.push({p.first*p.second/(p.second+1), p.second+1});
    }
    int q;
    cin >> q;
    while(q--){
        int k;  cin >> k;
        cout << fixed << setprecision(12) << pre[k] << endl;
    }
    return 0;
}