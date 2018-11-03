#include<iostream>
#include<bitset>
using namespace std;

int main(){
    int l, m, n, q, a, b;
    cin >> l >> m >> n;

    bitset<100000> A, B;

    for(int i = 0; i < l; i++){
        cin >> a;
        A[a-1] = 1;
    }

    for(int i = 0; i < m; i++){
        cin >> b;
        B[b-1] = 1;
    }

    cin >> q;

    for(int i = 0; i < q; i++){
        cout << (A&B).count() << endl;
        B <<= 1;
    }

    return 0;
}