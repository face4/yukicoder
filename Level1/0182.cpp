#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n+2] = {};
    for(int i = 1; i <= n; i++) cin >> A[i];
    sort(A+1, A+n+1);
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(A[i-1] != A[i] && A[i] != A[i+1]){
            res++;
        }
    }

    cout << res << endl;
    return 0;
}