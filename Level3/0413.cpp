// ???
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
    for(int i = 0; i < 100000; i++){
        ll x = 5e8+i;
        cout << x*x+x-1 << endl;
    }
    return 0;
}