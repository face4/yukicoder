#include<iostream>
#include<vector>
using namespace std;

int dfs(int p, vector<int> v){
    if(p < 0 || v.size() == 1)   return 0;
    vector<int> one, zero;
    for(int i = 0; i < v.size(); i++){
        if((v[i]>>p)&1) one.push_back(v[i]&((1<<p)-1));
        else            zero.push_back(v[i]&((1<<p)-1));
    }
    if(one.size() == 0)     return dfs(p-1, zero);
    if(zero.size() == 0)    return dfs(p-1, one);
    return (1<<p) + min(dfs(p-1,zero), dfs(p-1,one));
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    cout << dfs(30, a) << endl;

    return 0;
}