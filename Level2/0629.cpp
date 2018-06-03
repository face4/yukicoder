#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> edge[1001];
int A[1001];

// depth1までの幅優先探索を行う
bool bfs(int x){
    set<int> kado;
    kado.insert(A[x]);

    for(int i = 0; i < edge[x].size(); i++){
        kado.insert(A[edge[x][i]]);
    }

    if(kado.size() < 3) return false;

    int pos = distance(kado.begin(), kado.find(A[x]));

    if(pos < kado.size()-2 || pos > 1)  return true;
    else                                return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)     cin >> A[i];

    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(bfs(i)){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}