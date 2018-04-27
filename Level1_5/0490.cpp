#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];

    for(int i = 1; i < 2*n-3; i++){
        for(int p = 0; p < i; p++){
            int q = i-p;

            if(p < q && q <= n-1){
                if(A[p] > A[q]){
                    swap(A[p], A[q]);
                }
            }
            
        }
    }

    for(int i = 0; i < n; i++){
        cout << ((i == 0) ? "" : " ") << A[i];
    }

    cout << endl;
    return 0;
}