#include<iostream>
using namespace std;

int A[4] = {};
int n,count,l,r;

int main(){
    cin >> n;
    A[n] = 1;
    cin >> count;
    while(count-- > 0){
        cin >> l >> r;
        swap(A[l],A[r]);
    }

    for(int i = 1; i <= 3; i++){
        if(A[i] == 1){
            cout << i << endl;
        }
    }

    return 0;
}