#include<iostream>
using namespace std;

int main(){
    int n, v, t, s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        s += t;
    }
    cin >> v;
    cout << (s-v) << endl;
    return 0;
}