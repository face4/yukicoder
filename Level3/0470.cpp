#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> g[110], rev[110];
vector<int> vs, par(110);
vector<bool> used(110);

void add_edge(int from, int to){
    g[from].push_back(to);
    rev[to].push_back(from);
}

void dfs(int x){
    used[x] = true;
    for(int child : g[x]){
        if(!used[child])    dfs(child);
    }
    vs.push_back(x);    // postorder
}

void rdfs(int x, int k){
    used[x] = true;
    par[x] = k;
    for(int child : rev[x]){
        if(!used[child])    rdfs(child, k);
    }
}

int main(){
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++)  cin >> s[i];
    if(n > 52){
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k : {1, 2}){
                for(int l : {1, 2}){
                    set<string> x;
                    x.insert(s[i].substr(0, k));
                    x.insert(s[i].substr(k));
                    x.insert(s[j].substr(0, l));
                    x.insert(s[j].substr(l));
                    if(x.size() != 4){
                        add_edge(i+(k-1)*n, j+(3-l-1)*n);
                        add_edge(j+(l-1)*n, i+(3-k-1)*n);
                    }
                }
            }
        }
    }
    fill(used.begin(), used.end(), 0);
    for(int i = 0; i < n+n; i++){
        if(!used[i])    dfs(i);
    }
    fill(used.begin(), used.end(), 0);
    int k = 0;
    for(int i = vs.size()-1; i >= 0; i--){
        if(!used[vs[i]])    rdfs(vs[i], k++);
    }
    for(int i = 0; i < n; i++){
        if(par[i] == par[i+n]){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(par[i] > par[i+n]){
            cout << s[i].substr(0,1) << " " << s[i].substr(1) << endl;
        }else{
            cout << s[i].substr(0,2) << " " << s[i].substr(2) << endl;
        }
    }
    return 0;
}