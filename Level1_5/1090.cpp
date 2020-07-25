#include<iostream>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    int a[n];
    a[0] = 0;
    for(int i = 1; i < n; i++)  cin >> a[i], a[i] += a[i-1];
    cout << a[0];
    for(int i = 1; i < n; i++){
        if(a[i]-a[i-1] < d) a[i] = a[i-1]+d;
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}