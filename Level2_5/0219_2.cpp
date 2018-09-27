#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    int x, y, a, b;
    ll z;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        double l = log10(a) * b;
        z = l;
        l -= z;
        x = (pow(10, l) * 10);
        y = x%10;
        x /= 10;
        cout << x << " " << y << " " << z << endl;
    }

    return 0;
}