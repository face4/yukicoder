#include<iostream>
using namespace std;

int main(){
    string s;
    int i, j;
    cin >> s >> i >> j;
    swap(s[i], s[j]);
    cout << s << endl;
    return 0;
}