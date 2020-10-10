#include<iostream>
using namespace std;
typedef long long ll;

// 2^{a(p-1)} \equiv 1 mod p
// 2^x mod p はxにp-1を足すことでmod p上で1減らすことが可能
int main(){
    int n;
    cin >> n;
    while(n--){
        ll p;
        cin >> p;
        cout << 1+(p-1)*(p-1) << endl;
    }
    return 0;
}