#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << "285714"[(n-1)%6] << endl;
    return 0;
}