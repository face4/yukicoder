#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string res = "";
    while(n >= 7){
        res.insert(0, to_string(n%7));
        n /= 7;
    }
    res.insert(0, to_string(n));
    cout << res << endl;
    return 0;
}