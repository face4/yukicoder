#include<iostream>
using namespace std;

int calc(int m){
    int ret = 0, p = 2;
    while(m != 1){
        int cnt = 0;
        while(m % p == 0)   m /= p, cnt++;
        ret ^= cnt%3; // grundy数は0,1,2,0,1,2,...
        p++;
    }
    return ret;
}

int main(){
    int n, m;
    cin >> n;

    int nim = 0;

    while(n-- > 0){
        cin >> m;
        nim ^= calc(m);
    }

    if(nim == 0)    cout << "Bob" << endl;
    else            cout << "Alice" << endl;

    return 0;
}