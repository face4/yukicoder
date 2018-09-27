#include<iostream>
using namespace std;

typedef unsigned long long ll;

int main(){
    int p;
    cin >> p;

    ll ans = 1;
    for(int i = 0; i < p; i++)  ans *= 10;

    ll sub = 6;
    for(int i = 0; i < p-1; i++)    sub *= 9;

    cout << ans-sub-1 << endl;

    return 0;
}