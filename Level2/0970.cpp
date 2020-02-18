#include<iostream>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    int sum = accumulate(a, a+n, 0);
    for(int i = 0; i < n; i++){
        cout << sum-a[i]*(n-1) << " \n"[i==n-1];
    }
    return 0;
}