#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    
    int cnt[26] = {};
    for(char x : s) cnt[x-'a']++;

    int ans = cnt[25];
    while(cnt[24]){
        cnt[24]--;
        int i, j, k, l;
        for(i = 20; i < 26; i++)    if(cnt[i]) {cnt[i]--; break;}
        if(i == 26) break;
        if(i > 20) {ans++; continue;}
        for(j = 10; j < 26; j++)    if(cnt[j]) {cnt[j]--; break;}
        if(j == 26) break;
        if(j > 10) {ans++; continue;}
        for(k = 8; k < 26; k++)     if(cnt[k]) {cnt[k]--; break;}
        if(k == 26) break;
        if(k > 8)  {ans++; continue;}
        for(l = 0; l < 26; l++)     if(cnt[l]) {cnt[l]--; break;}
        if(l == 26) break;
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}