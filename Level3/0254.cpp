// 自力AC
#include<iostream>
using namespace std;
typedef long long ll;

ll calc(ll x){
    ll n = x/2+1;
    return x*n-n*(n-1);
}

int main(){
    ll n;
    cin >> n;
    string ret = "";
    auto f = [](int x, int y)->char{
        return (char)('a'+(x+y)%26);
    };
    int pos = 0;
    while(n){
        ll tmp = 0, len = 0, flag = 0;
        while(calc(len+1) <= n){
            len++;
            ret += f(pos, flag);
            flag = 1-flag;
        }
        n -= calc(len);
        pos += 2;
        pos %= 26;
    }
    cout << ret << endl;
    return 0;
}