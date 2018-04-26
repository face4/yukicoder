#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if(k == 0 || k > n){
        cout << 0 << endl;
    }else{
        cout << n-2 + (n%2 == 1 && n/2 == k-1 ? 1 : 0) << endl;
    }
    return 0;
}