#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int n, m, r;
    scanf("%d %d", &n, &m);

    int deg[100000] = {};
    int paramax[10] = {};

    vector<stack<int>> v(m);
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &r);
            if(r > paramax[j]){
                while(!v[j].empty()){
                    int person = v[j].top(); v[j].pop();
                    deg[person]--;
                    if(deg[person] == 0)    ans--;
                }
                paramax[j] = r;
                deg[i]++;
                if(deg[i] == 1) ans++;
                v[j].push(i);
            }else if(r == paramax[j]){
                v[j].push(i);
                deg[i]++;
                if(deg[i] == 1) ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}