#include<iostream>
using namespace std;

int main(){
    int n, s = 0, A[100] = {}, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        s += A[i];
    }
    s /= 10;
    for(int i = 0; i < n; i++){
        if(A[i] <= s){
            res += 30;
        }
    }
    cout << res << endl;
    return 0;
}