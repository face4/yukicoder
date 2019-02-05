#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v[n];
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<bool> bought(n, 0);
    string res = "";
    for(int i = n-1; i >= 0; i--){
        bool buy = false;
        for(int to : v[i]){
            if(to > i && !bought[to])   buy = true;
        }
        if(buy){
            res += "1";
            bought[i] = true;
        }else{
            res += "0";
        }
    }

    int cur = 0;
    while(res[cur] == '0')  cur++;
    res = res.substr(cur);

    cout << res << endl;

    return 0;
}