#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n > 10)  cout << 10 << " " << n-10 << endl;
    else        cout << 1 << " " << n-1 << endl;
    return 0;
}