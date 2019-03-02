#include<iostream>
#include<vector>
using namespace std;

int main(){
    int r, b;
    string s;
    cin >> r >> b >> s;
    auto check = [=](string t)->bool{
        int n = t.length();
        for(int i = 0; i < n; i++){
            if(t[i] == 'R'){
                if(i-r >= 0 && t[i-r] == 'R')    return false;
                if(i+r < n && t[i+r] == 'R')    return false;
            }
            if(t[i] == 'B'){
                if(i-b >= 0 && t[i-b] == 'B')    return false;
                if(i+b < n && t[i+b] == 'B')    return false;
            }
        }
        return true;
    };
    vector<int> v;
    int ans = 10;
    for(int i = 0; i < 30; i++) if(s[i] != 'W') v.push_back(i);
    for(int i = 0; i < 1<<20; i++){
        vector<bool> use(30, true);
        for(int j = 0; j < 20; j++) if((i>>j)&1)    use[v[j]] = false;
        string t = "";
        for(int j = 0; j < 30; j++) if(use[j])  t += s.substr(j,1);
        if(check(t))    ans = max(ans, (int)t.length());
    }
    cout << ans << endl;
    return 0;
}