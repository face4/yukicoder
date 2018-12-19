#include<iostream>
using namespace std;

int main(){
    string s = "0";
    for(int i = 1; i <= 100; i++)   s += to_string(i);
    int n;
    cin >> n;
    cout << s[n] << endl;
    return 0;
}