#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    set<pii> s;
    map<pii,int> m;
    vector<int> deg(n+1, 0), v[n+1];
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        deg[x]++, deg[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
        if(x > y)   swap(x, y);
        s.insert({x,y});
        m[{x,y}] = i;
    }
    queue<int> leaf;
    for(int i = 1; i <= n; i++) if(deg[i] == 1) leaf.push(i);
    while(!leaf.empty()){
        int l = leaf.front();   leaf.pop();
        for(int next : v[l]){
            deg[next]--;
            s.erase({min(l,next), max(l,next)});
            if(deg[next]==1)    leaf.push(next);
        }
    }
    cout << s.size() << endl;
    bool f = true;
    for(pii p : s){
        if(f)   f = false;
        else    cout << " ";
        cout << m[p];
    }
    cout << endl;
    return 0;
}