#include<iostream>
using namespace std;

int main(){
    int m = 0, n;
    cin >> n;
    int A[n], a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        A[i] = a + 4*b;
        m = max(A[i], m);
    }
    long long res = 0;
    for(int i = 0; i < n; i++){
        if((m-A[i])%2 == 0) res += (m-A[i])/2;
        else{
            cout << -1 << endl;
            return 0;
        }
    }

    cout << res << endl;
    return 0;
}