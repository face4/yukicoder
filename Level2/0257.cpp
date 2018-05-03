#include<iostream>
using namespace std;

int main(){
    int n, k, my = 0, enemy;

    if((n-1)%(k+1) == 0){
        cout << 0 << endl << flush;
    }else{
        my = (n-1)%(k+1); 
        cout << my << endl << flush;
    }    

    while(1){
        cin >> enemy;
        if(enemy >= n)  break;
        my += k+1;
        cout << my << endl << flush;
    }
    return 0;
}