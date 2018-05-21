#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll fermat[5] = {3, 5, 17, 257, 65537};
    int a, cnt = 0;
    cin >> a;

    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 32; j++){
            ll candidate = 1ll<<i;
            if(j&1) candidate *= 3;
            if(j&2) candidate *= 5;
            if(j&4) candidate *= 17;
            if(j&8) candidate *= 257;
            if(j&16) candidate *= 65537;

            if(candidate >= 3 && candidate <= a)    cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}