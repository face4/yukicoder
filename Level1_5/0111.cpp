#include<iostream>
using namespace std;

int main(){
    long long  l;
    cin >> l;
    l = (l-1)/2;
    long long res = l--;
    res += l*(l+1);
    cout << res << endl;
    return 0;
}