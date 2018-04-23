#include<iostream>
using namespace std;

int main(){
    long long n, tmp;
    cin >> n;
    tmp = n;
    while(tmp != 0){
        tmp /= 2;
        n -= tmp;
    }
    cout << n << endl;
    return 0;
}