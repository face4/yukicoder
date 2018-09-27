#include<iostream>
using namespace std;

int main(){
    int n, k, a, ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        ans ^= a%(k+1);
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}