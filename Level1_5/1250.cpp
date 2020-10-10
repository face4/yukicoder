#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n, h;
    cin >> n >> h;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(x == 0){
            cout << "YES" << endl;
            return 0;
        }
        x = abs(x);
        int g = gcd(x, h);
        h /= g;
    }
    cout << (h==1 ? "YES" : "NO") << endl;
    return 0;
}