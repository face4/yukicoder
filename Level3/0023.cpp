#include<iostream>
using namespace std;

int main(){
    int h, a, d;
    cin >> h >> a >> d;

    double ans = (h+a-1)/a;
    for(int i = 0; i < (h+a-1)/a; i++){
        ans = min(ans, i + (h-a*i+d-1)/d * 3.0 / 2.0);
    }

    cout << ans << endl;
    
    return 0;
}