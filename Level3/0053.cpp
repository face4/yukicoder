#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    double ans = 4.0;
    for(int i = 0; i < n; i++){
        ans *= 3.0;
        ans /= 4.0;
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}