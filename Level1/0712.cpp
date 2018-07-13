#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    char a;
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a;
            if(a == 'W')    ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}