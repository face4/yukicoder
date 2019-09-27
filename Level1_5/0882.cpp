#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    bool valid = false;
    for(int i = 1; i <= a; i++){
        if(a%i) continue;
        valid |= a%b==0;
    }
    cout << (valid ? "YES" : "NO") << endl;
    return 0;
}