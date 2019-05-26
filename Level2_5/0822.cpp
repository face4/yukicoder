#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    if(n < k){
        cout << "INF" << endl;
        return 0;
    }
    
    int ans = 0;
    for(int s = 0; s < (1<<18); s++){
        bool ok = true;
        int x = n;
        for(int j = 0; j < 18; j++){
            if(((s>>j)&1) == 1 && ((n>>j)&1) == 1)  ok = false;
            if((s>>j)&1)    x += 1<<j;
        }
        if(!ok) continue;
        for(int add = 0; add <= k; add++){
            if((x&(x+add)) == n)  ans++;
        }
    }

    cout << ans << endl;

    return 0;
}