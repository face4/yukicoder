#include<iostream>
using namespace std;

int main(){
    int pos = 0, t, x;
    cin >> t;
    while(t-- > 0){
        cin >> x;
        if(abs(pos-x) != 1){
            cout << "F" << endl;
            return 0;
        }
        pos = x;
    }

    cout << "T" << endl;
    return 0;
}