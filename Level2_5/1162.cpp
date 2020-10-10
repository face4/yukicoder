// editorial
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll t = sqrt(n);
    if(t*t > n) t--;
    cout << t+n/(t+1) << endl;
    return 0;
}