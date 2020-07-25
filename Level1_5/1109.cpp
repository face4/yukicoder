#include<iostream>
#include<cassert>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    assert(1 <= n && n <= 12);

    bool t[12] = {};
    int bef = -1;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        assert(0 <= x && x < 12);
        assert(bef < x);
        assert(!t[x]);
        t[x] = true;
        bef = x;
    }

    int ans = -1;
    for(int i = 0; i < 12; i++){
        int cnt = 0;
        for(int j : {0, 2, 4, 5, 7, 9, 11}){
            cnt += t[(j+i)%12];
        }
        if(cnt != n)    continue;
        if(ans != -1){
            cout << -1 << endl;
            return 0;
        }
        ans = i;
    }
    
    cout << ans << endl;

    return 0;
}