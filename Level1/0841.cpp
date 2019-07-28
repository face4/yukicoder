#include<iostream>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    bool a = s == "Sat" || s == "Sun";
    bool b = t == "Sat" || t == "Sun";
    if(a&&b)    cout << "8/33" << endl;
    else if(a)  cout << "8/32" << endl;
    else        cout << "8/31" << endl;
    return 0;
}