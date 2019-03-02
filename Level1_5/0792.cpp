#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(1<<n, vector<int>(n+1));
    int cnt = 0;
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n+1; j++){
            cin >> v[i][j];
        }
        cnt += v[i][n];
    }
    cout << "A=";
    if(cnt == 0){
        cout << "⊥" << endl;
        return 0;
    }else if(cnt == 1<<n){
        cout << "⊤" << endl;
        return 0;
    }
    vector<string> ans;
    for(int i = 0; i < (1<<n); i++){
        if(v[i][n] == 0)    continue;
        string t = "(";
        for(int j = 0; j < n; j++){
            if(j)   t += "∧";
            if(v[i][j] == 0)    t += "¬";
            t += "P_" + to_string(j+1);
        }
        t += ")";
        ans.push_back(t);
    }
    for(int i = 0; i < ans.size(); i++){
        if(i)   cout << "∨";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}