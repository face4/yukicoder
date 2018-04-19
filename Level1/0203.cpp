#include<iostream>
using namespace std;

int main(){
    int res = 0, n = 0;
    char c;
    for(int i = 0; i < 14; i++){
        cin >> c;
        if(c == 'x'){
            res = max(n,res);
            n = 0;
        }else if(c == 'o'){
            n++;
        }
    }
    res = max(n,res);
    cout << res << endl;
    return 0;
}