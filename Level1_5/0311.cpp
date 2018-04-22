#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll res = 0;
    ll N;
    cin >> N;
    res = 2 * (N / 3 + N / 5);
    cout << res << endl;
    return 0;
}