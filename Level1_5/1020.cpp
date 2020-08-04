#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    string a = s.substr(k-1), b = s.substr(0, k-1);
    if((n-k+1)%2) reverse(b.begin(), b.end());
    cout << a << b << endl;
    return 0;
}