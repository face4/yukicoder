#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    double x, y, h;
    cin >> x >> y >> h;
    x *= 1000, y *= 1000;
    int ans = 0;
    while(max(x,y) > h){
        if(x > y)   swap(x, y);
        (x > h ? x : y) /= 2;
        h *= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}