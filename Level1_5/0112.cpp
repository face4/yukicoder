#include<iostream>
using namespace std;

int main(){
    int n, sum = 0, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        sum += a;
    }

    sum /= n-1;
    cout << 2*n-sum/2 << " " << sum/2-n << endl;
    return 0;
}