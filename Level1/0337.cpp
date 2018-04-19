#include<iostream>
using namespace std;

int main(){
    int n,p;
    cin >> n >> p;
    if(p == (n * p))    cout << "=";
    else                cout << "!=";
    cout << endl;
    return 0;
}