#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    double table[90] = {};
    for(int i = 0; i < 90; i++){
        table[i] = log10(i+10) - 1;
    }

    int a, b, y;
    ll z;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        double x = log10(a) * b;
        z = x;
        x -= z;
        y = lower_bound(table, table+90, x) - table -1 + 10;
        y = max(10, y);
        cout << y/10 << " " << y%10 << " " << z << endl;
    }
 
    return 0;
}