#include<iostream>
using namespace std;

int main(){
    int x, y, d;
    cin >> x >> y >> d;
    int ans = d+1;
    if(x < d)   ans -= d-x; 
    if(y < d)   ans -= d-y;
    cout << max(ans, 0) << endl;
    return 0;
}
/* 遅い
int main(){
    int x, y, d;
    cin >> x >> y >> d;
    int ans = 0;
    for(int i = 0; i <= x; i++){
        if(y >= -i+d && -i+d >= 0)   ans++;
    }

    cout << ans << endl;
    return 0;
}
*/