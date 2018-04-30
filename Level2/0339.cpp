#include<iostream>
using namespace std;

int getGCD(int a, int b){
    return b == 0 ? a : getGCD(b, a%b);
}

int main(){
    int n;
    cin >> n;
    int A[n];
    int gcd;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        if(i == 0)  gcd = A[i];
        else        gcd = getGCD(gcd, A[i]);
    }

    cout << 100/gcd << endl;
    return 0;
}