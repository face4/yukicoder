#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int v[n];
    for(int i = 0; i < n; i++)  v[i] = i;

    int x, y;
    for(int i = 0; i < k; i++){
        cin >> x >> y;
        swap(v[--x], v[--y]);
    }

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    vector<pair<int,int>> ans;
    // バブルソート。末尾から確定していく
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            if(a[v[j]] > a[v[j+1]]){
                ans.push_back({j+1, j+2});
                swap(v[j], v[j+1]);
            }
        }
    }

    cout << ans.size() << endl;

    for(pair<int,int> p : ans)  cout << p.first << " " << p.second << endl;

    return 0;
}