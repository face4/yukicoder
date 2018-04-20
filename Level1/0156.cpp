#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    int C[n];
    for(int i = 0; i < n; i++) cin >> C[i];

    sort(C, C+n);

    int sum = 0, i;
    for(i = 0; i < n; i++){
        int a = min(m-sum, C[i]);
        sum += a;
        C[i] -= a;
        if(sum >= m) break;
    }
    if(C[i] != 0)   i--;
    cout << (i+1) << endl;
    return 0;
}