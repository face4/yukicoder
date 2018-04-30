#include<iostream>
using namespace std;

int main(){
    int d;
    cin >> d;
    int A[d+1];
    for(int i = 0; i <= d; i++)  cin >> A[i];
    for(int i = d; i >= 3; i--) A[i-2] += A[i];

    int zisu;
    if(d < 2)           zisu = d;
    else if(A[2] != 0)  zisu = 2;
    else if(A[1] != 0)  zisu = 1;
    else                zisu = 0;

    cout << zisu << endl;

    for(int i = 0; i <= zisu; i++){
        if(i != 0) cout << " ";
        cout << A[i];
    }

    return 0;
}