#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    cin >> s;
    int d = s.size() - 10;
    cout << (d > 0 ? d : -d) << endl;
    return 0;
}