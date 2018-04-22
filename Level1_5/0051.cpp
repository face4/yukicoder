#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int main(){
    ll w, d;
    cin >> w >> d;
    for(ll i = d; i > 1; i--){
        w -= w / (i*i);
    }
    cout << w << endl;
    return 0;
}