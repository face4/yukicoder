#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    cout << s << (s == "ham" ? "" : "ham") << endl;
    return 0;
}