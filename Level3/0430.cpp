#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    ll times[10] = {};
    times[0] = 1;
    for(int i = 1; i < 10; i++){
        times[i] = times[i-1]*26;
    }

    string s;
    cin >> s;

    int n = s.length();
    vector<vector<ll>> hash(11);
    
    for(int i = 1; i <= min(n, 10); i++){
        ll roll = 0;
        for(int j = 0; j < i; j++)  roll = roll*26 + s[j]-'A';
        hash[i].push_back(roll);
        for(int j = i; j < n; j++){
            roll %= times[i-1];
            roll *= 26;
            roll += s[j]-'A';
            hash[i].push_back(roll);
        }
    }

    for(int i = 1; i < 11; i++) sort(hash[i].begin(),hash[i].end());

    int m;
    cin >> m;

    string c;
    int ans = 0;
    for(int i = 0; i < m; i++){
        cin >> c;
        int clen = c.length();
        ll target = 0;
        for(int j = 0; j < clen; j++){
            target = target*26 + (c[j]-'A');
        }
        ans += upper_bound(hash[clen].begin(),hash[clen].end(),target)-lower_bound(hash[clen].begin(),hash[clen].end(),target);
    }

    cout << ans << endl;
    
    return 0;
}