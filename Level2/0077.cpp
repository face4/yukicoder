#include<iostream>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[201] = {};
    for(int i = 0; i < n; i++) cin >> a[i];

    int sum = accumulate(a, a+101, 0);
    int m = 1;
    while((m+1)*(m+1) <= sum)   m++;

    //int residual = sum - m*m;
    int excess = 0; //, lack = 0;

    for(int i = 0; i < m; i++){
        if(a[i] > i+1)  excess += a[i] - (i+1);
        //else            lack += (i+1) - a[i];
    }
    for(int i = m; i < m+m-1; i++){
        if(a[i] > m+m-i-1)  excess += a[i] - (m+m-i-1);
        //else                lack += (m+m-i-1) - a[i];
    }
    for(int i = m+m-1; i < n; i++){
        excess += a[i];
    }

    cout << excess << endl;

    return 0;
}