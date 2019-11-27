#include<iostream>
#include<vector>
#include<set>
using namespace std;

// 自力AC
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), v[n];
    set<int> s[n];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    for(int next : v[0]){
        for(int j : v[next]){
            if(j != 0)  s[j].insert(next);
        }
    }

    for(int i = 0; i < m; i++){
        int x = a[i], y = b[i];
        if(s[x].empty() || s[y].empty())    continue;
        bool c = s[x].count(y);
        bool d = s[y].count(x);
        if(c)   s[x].erase(y);
        if(d)   s[y].erase(x);
        if(s[x].empty() || s[y].empty() || (s[x].size() == 1 && s[x].size() == s[y].size() && *s[x].begin()==*s[y].begin())){
            if(c)   s[x].insert(y);
            if(d)   s[y].insert(x);
            continue;
        }
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}