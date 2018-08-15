#include<iostream>
using namespace std;

int n;
int ansi = -1, ansj = -1, ansk = -1;
int a[20];

bool dfs(int bitmask){
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                // bitmask状況下においてi, j, kを選択できる
                bool x = ~bitmask&(1<<i) && ~bitmask&(1<<j) && ~bitmask&(1<<k);
                // i, j, kが門松列を成す
                bool y = x && (a[i]-a[j])*(a[k]-a[j]) > 0;
                // 必勝
                bool z = y && !dfs(bitmask | (1<<i) | (1<<j) | (1<<k));
                
                if(z){
                    ansi = i, ansj = j, ansk = k;
                    return true;
                }
            }
        }
    }
    // bitmask状況下において新しく門松列を作ることが出来ない
    return false;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++)  cin >> a[i];

    if(dfs(0))  cout << ansi << " " << ansj << " " << ansk << endl;
    else        cout << -1 << endl;

    return 0;
}
