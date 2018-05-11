#include<iostream>
#include<algorithm>
using namespace std;

long long A[100000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> A[i];
    sort(A, A+n);
    long long median = -1;
    if(n % 2 == 0)  median = (A[n/2]+A[n/2-1])/2;
    else            median = A[n/2];

    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(A[i]-median);
    }
    cout << ans << endl;
    return 0;
}