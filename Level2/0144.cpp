// 正直　微妙
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int factor[1000001] = {};

int main(){
    int n;
    double p;

    cin >> n >> p;

    for(int i = 2; i <= n; i++){
        for(int j = i+i; j <= n; j += i){
            factor[j]++;
        }
    }

    double ans = 0;
    for(int i = 2; i <= n; i++){
        ans += pow(1-p, factor[i]);
    }

    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}