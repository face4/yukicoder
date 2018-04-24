// 10^6以下の適当な正整数を出力するだけでよい.
#include<iostream>
#include<cmath>
using namespace std;

#define PI 3

int main(){
    long double n;
    cin >> n;
    n  = n /3;
    cout << (long)(sqrt(n)) + 1 << endl;
    return 0;
}