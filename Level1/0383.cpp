#include<iostream>
using namespace std;

int main(){
    int a, b, diff;
    cin >> a >> b;
    diff = b-a;
    if(diff > 0) cout << "+";
    cout << diff << endl;
    return 0;
}