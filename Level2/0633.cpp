#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n-1];
    for(int i = 0; i < n-1; i++){
        cin >> A[i];
    }

    int b, c, now;
    cin >> b >> c;
    now = c - b;
    long long fee = 0;

    for(int i = 2; i <= n; i++){
        fee += now * A[i-2];
        cin >> b >> c;
        now = now - b + c;
    }

    cout << fee << endl;
    return 0;
}