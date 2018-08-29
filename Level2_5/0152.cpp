// mod要らなくない...?
#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

bool coprime(int i, int j){
    return gcd(i, j) == 1;
}

int main(){
    int l;
    cin >> l;

    int ans = 0;
    for(int m = 2; 8*m*m <= l; m++){
        for(int n = 1; n < m; n++){
            if((m-n)%2 == 0 || !coprime(n,m))    continue;
            int tmplen = 4*(2*m*m + 2*m*n);
            if(tmplen <= l){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}