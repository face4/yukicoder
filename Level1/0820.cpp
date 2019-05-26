#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if(n < k)   cout << 0 << endl;
    else        cout << (1<<(n-k)) << endl;
    return 0;
}