#include<iostream>
using namespace std;
typedef long long ll;

int A[100001];
int mod = 1000000007;

int main(){
    int n;
    cin >> n;

    A[1] = 1;
    A[2] = 2;
    A[3] = 6;
    ll odd = 1;
    ll even = 2;
    for(int i = 4; i <= n; i++){
        if(i%2 == 0){
            odd = (odd+A[i-1])%mod;
            A[i] = (i*odd)%mod;
        }else{
            even = (even+A[i-1])%mod;
            A[i] = (i*even)%mod;
        }
    }

    cout << A[n] << endl;
    return 0;
}