#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n < 2){
        cout << 0 << endl;
        return 0;
    }

    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A, A+n);
    int mi = 1000001;
    for(int i = 0; i < n-1; i++){
        if(A[i+1] == A[i]) continue;
        mi = min(mi, abs(A[i+1]-A[i]));
    }
    if(mi == 1000001) mi = 0;
    cout << mi << endl;
    return 0;
}