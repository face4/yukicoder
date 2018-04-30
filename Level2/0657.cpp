#include<iostream>
using namespace std;

#define SIZE 1000001
int T[SIZE];

int main(){
    T[0] = 1; // 便宜上
    T[1] = T[2] = T[3] = 0;
    T[4] = 1;
    for(int i = 5; i < SIZE; i++){
        T[i] = (2*T[i-1] - T[i-5]) % 17;
        if(T[i] < 0)    T[i] += 17;
    }

    int q, n;
    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> n;
        cout << T[n] << endl;
    }
    return 0;
}