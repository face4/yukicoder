#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

vector<int> v[100], rev[100], vs, par(100);
vector<bool> used(100);

void dfs(int x){
    used[x] = true;
    for(int next : v[x]){
        if(!used[next]) dfs(next);
    }
    vs.push_back(x);    // postorder
}

void rdfs(int x, int k){
    used[x] = true;
    par[x] = k;
    for(int next : rev[x]){
        if(!used[next]) rdfs(next, k);
    }
}

int main(){
    int n;
    cin >> n;
    vector<double> score(n);
    for(int i = 0; i < n; i++){
        int s;
        cin >> score[i] >> s;
        s--;
        v[s].push_back(i);
        rev[i].push_back(s);
    }
    fill(used.begin(), used.end(), 0);
    for(int i = 0; i < n; i++){
        if(!used[i])    dfs(i);
    }
    fill(used.begin(), used.end(), 0);
    int comp = 0;
    for(int i = n-1; i >= 0; i--){
        if(!used[vs[i]])    rdfs(vs[i], comp++);
    }
    double ans = accumulate(score.begin(), score.end(), 0) / 2.0;
    for(int i = 0; i < comp; i++){
        bool in = false;
        double mi = 1e9;
        for(int j = 0; j < n; j++){
            if(par[j] != i) continue;
            mi = min(mi, score[j]);
            for(int k : rev[j]){
                in |= par[k] != i;
            }
        }
        if(in)  continue;
        ans += mi/2;
    }
    printf("%.1f\n", ans);
    return 0;
}