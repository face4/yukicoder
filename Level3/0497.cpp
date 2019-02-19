#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> x(n), y(n), z(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
        if(y[i] > z[i]) swap(y[i], z[i]);
        if(x[i] > y[i]) swap(x[i], y[i]);
        if(y[i] > z[i]) swap(y[i], z[i]);
    }

    vector<int> v[n], indeg(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)  continue;
            if(x[i] < x[j] && y[i] < y[j] && z[i] < z[j]){
                v[i].push_back(j);
                indeg[j]++;
            }
        }
    }

    vector<int> ans(n, 1);
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0)   q.push(i);
    }

    int ret = 0;
    while(!q.empty()){
        int p = q.front();  q.pop();
        ret = max(ret, ans[p]);
        for(int next : v[p]){
            indeg[next]--;
            ans[next] = max(ans[next], ans[p]+1);
            if(indeg[next] == 0)    q.push(next);
        }
    }

    cout << ret << endl;

    return 0;
}