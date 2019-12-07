// editorialを読んだ
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i], a[i]--;
    vector<int> cnt(n+1, 0);
    vector<bool> vis(n, 0);
    for(int i = 0; i < n; i++){
        if(vis[i])  continue;
        int len = 0;
        int now = i;
        while(!vis[now]){
            vis[now] = true;
            len++;
            now = a[now];
        }
        if(len%2 == 0) cnt[len]++;
    }
    bool ok = true;
    for(int i = 0; i <= n; i+=2)    ok &= cnt[i]%2==0;
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}