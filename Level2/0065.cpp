#include<iostream>
using namespace std;

int main(){
    double E[27] = {};
    int k;
    cin >> k;
    
    for(k--;k >= 0; k--){
        E[k] = 1.0 + (E[k+1]+E[k+2]+E[k+3]+E[k+4]+E[k+5]+E[k+6])/6.0;
    }

    cout << E[0] << endl;
    return 0;
}