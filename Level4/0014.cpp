#include<iostream>
#include<set>
#include<vector>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n), divs[n];
    set<pair<int,int>> s[10001];
    for(int i = 0; i < n; i++){
        cin >> v[i];
        for(int j = 1; j*j <= v[i]; j++){
            if(v[i]%j)  continue;
            divs[i].push_back(j);
            s[j].insert({v[i], i});
            if(j*j != v[i]){
                divs[i].push_back(v[i]/j);
                s[v[i]/j].insert({v[i], i});
            }
        }
    }
    vector<int> ans;
    int use = 0;
    for(int i = 0; i < n; i++){
        ans.push_back(v[use]);
        int take = -1;
        pair<int,int> tmp(1<<30,10001); // gcd, val
        for(int d : divs[use]){
            s[d].erase({v[use], use});
            if(s[d].empty())    continue;
            pair<int,int> cand = *(s[d].begin());
            int lcm = cand.first*v[use]/gcd(cand.first, v[use]);
            pair<int,int> q(lcm, cand.first);
            if(q < tmp){
                tmp = q;
                take = cand.second;
            }
        }
        use = take;
    }
    for(int i = 0; i < n; i++)  cout << ans[i] << " \n"[i==n-1];
    return 0;
}