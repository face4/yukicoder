#include<iostream>
using namespace std;

int main(){
    // both {} and {0} make an array initialized by 0
    int A[14] = {}, B[5] = {}, val; 
    
    for(int i = 0; i < 5; i++){
        cin >> val;
        A[val]++;
    }

    for(int i = 1; i < 14; i++){
        B[A[i]]++;
    }

    if(B[3] == 1){
        if(B[2] == 1) cout << "FULL HOUSE";
        else          cout << "THREE CARD";
    }else if(B[2] == 2){
        cout << "TWO PAIR";
    }else if(B[2] == 1){
        cout << "ONE PAIR";
    }else{
        cout << "NO HAND";
    }

    cout << endl;
    return 0;
}