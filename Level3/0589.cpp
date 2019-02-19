#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    int cnt = 0;
    for(int i = 0; i < 60; i++) if((n>>i)&1)    cnt++;

    cout << n + 1 - (1ll<<cnt) << endl;

    return 0;
}