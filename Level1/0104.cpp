#include<iostream>
using namespace std;

int main(){
    int res = 1;
    char c;
    for(; cin >> c;){
        if(c == 'L') res *= 2;
        else if(c == 'R') res = 2*res + 1;
    }
    cout << res << endl;
    return 0;
}