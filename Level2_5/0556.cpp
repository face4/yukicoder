#include<iostream>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m;

    int uf[n+1];
    for(int i = 1; i <= n; i++)  uf[i] = i;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(uf[a] == uf[b])    continue;

        int numa = 0, numb = 0;
        for(int i = 1; i <= n; i++){
            if(uf[i] == uf[a])    numa++;
            if(uf[i] == uf[b])    numb++;
        }

        int from, to;
        if(numa == numb){
            from = max(uf[a],uf[b]);
            to = min(uf[a],uf[b]);
        }else if(numa > numb){
            from = uf[b];
            to = uf[a];
        }else if(numa < numb){
            from = uf[a];
            to = uf[b];
        }

        for(int i = 1; i <= n; i++){
            if(uf[i] == from)   uf[i] = to;
        }
    }

    for(int i = 1; i <= n; i++)  cout << uf[i] << endl;

    return 0;
}