#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll x, y, z;
    cin >> x >> y >> z;
    int cnt = (z>=x) + (z>=y);
    cout << z-cnt << endl;
    return 0;
}