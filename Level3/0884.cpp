#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v;
    for(int i = 0; i < n;){
        char c = s[i];
        int cnt = 1;
        while(i+1 < n && c == s[i+1])   cnt++, i++;
        i++;
        v.push_back(cnt);
    }
    int ans = 0;
    for(int i = 0; i < v.size();){
        bool notone = v[i] != 1;
        int cnt = 1;
        i += 2;
        while(i < v.size() && v[i-1] == 1){
            cnt++;
            notone |= (v[i] != 1);
            i += 2;
        }
        ans += cnt + (notone);
    }
    cout << ans << endl;
    return 0;
}