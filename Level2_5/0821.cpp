#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    cout << n*k + (1-k)*k/2 + 1 << endl;
    return 0;
}