#include<iostream>
using namespace std;

int main(){
    int l, n;
    cin >> l >> n;
    long long res = n;
    for(int i = l-3; i > 0; i--){
        res *= 2;
    }
    cout << res << endl;
    return 0;
}