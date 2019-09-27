#include <iostream>
#include <iomanip>
using namespace std;

const double d[6] = {0.083333333333, 0.166666666667, 0.250000000000, 0.083333333333, 0.250000000000, 0.166666666667};
bool memo[1000001] = {};
double b[1000001] = {};

double dfs(int x){
    if (x <= 0)     return 0;
    if (memo[x])    return b[x];
    memo[x] = true;
    b[x] = 1.0;
    for (int j = 1; j <= 6; j++)    b[x] += dfs(x-j)*d[j-1];
    return b[x];
}

int main(){
    /*  実験
    double d[6] = {}, a[7] = {};
    for(int i = 1; i <= 6; i++) cin >> a[i];
    for(int i = 2; i <= 6; i++){
        double tmp = a[i] - 1.0;
        for(int j = 1; j+1 < i; j++){
            tmp -= a[i-j]*d[j];
        }
        d[i-1] = tmp/a[1];
    }
    cout << fixed << setprecision(12);
    for(int i = 1; i <= 5; i++){
        cout << d[i] << endl;
    }
    cout << 1-d[1]-d[2]-d[3]-d[4]-d[5] << endl;
    */

    int q;
    cin >> q;
    while (q-- > 0){
        int n;
        cin >> n;
        cout << fixed << setprecision(15) << dfs(n) << endl;
    }

    return 0;
}
