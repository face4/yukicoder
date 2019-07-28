#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v[26];
    for(int i = 0; i < 26; i++) v[i].push_back(-1);
    for(int i = 0; i < n; i++){
        v[s[i]-'a'].push_back(i);
    }
    for(int i = 0; i < 26; i++) v[i].push_back(n);
    double div = (double)(n) * (n+1) / 2.0;
    double ans = 0;
    for(int i = 0; i < 26; i++){
        if(v[i].size() == 2)    continue;
        double tmp = div;
        for(int j = 1; j < v[i].size(); j++){
            tmp -= (double)(v[i][j]-v[i][j-1]-1)*(v[i][j]-v[i][j-1])/2;
        }
        ans += tmp/div;
    }
    cout << fixed << setprecision(12) << ans << endl;
}