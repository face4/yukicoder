#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b==0 ? a : gcd(b, a%b);
}

int main(){
    int m, n;
    cin >> m >> n;
    int g = gcd(m,n);
    m /= g;
    n /= g;

    int ans = 0;
    while(n != 1){
        ans += m/n;
        m -= m/n*n;
        swap(n,m);
        ans++;
    }

    ans += m-1;
    cout << ans << endl;
    return 0;
}