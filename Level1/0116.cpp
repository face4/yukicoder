#include<iostream>
using namespace std;

int main(){
    int n, res = 0;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];

    for(int i = 1; i < n-1; i++){
        if(A[i] == A[i-1] || A[i-1] == A[i+1] || A[i+1] == A[i]) continue;
        if((A[i-1] > A[i] && A[i] > A[i+1]) || (A[i-1] < A[i] && A[i] < A[i+1])){
        }else{
            res++;
        }
    }

    cout << res << endl;
    return 0;
}