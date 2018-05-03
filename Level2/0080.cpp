#include<iostream>
using namespace std;

int main(){
    int d;
    cin >> d;
    if(d%2 == 1)    d--;

    if(d%4 == 0){
        cout << d*d/16 << endl;
    }else if(d%2 == 0){
        cout << (d*d-4)/16 << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}