#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int m[n];
    for(int i = 0; i < n; i++)  cin >> m[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(m[i] < m[j]) continue;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}