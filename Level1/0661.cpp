#include<iostream>
using namespace std;

int main(){
    int i,x;
    cin >> i;
    while(i-- > 0){
        cin >> x;
        if(x % 40 == 0){
            cout << "ikisugi";
        }else if(x % 8 == 0){
            cout << "iki";
        }else if(x % 10 == 0){
            cout << "sugi";
        }else{
            cout << (x/3);
        }
        cout << endl;
    }
}