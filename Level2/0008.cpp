#include<iostream>
using namespace std;

int main(){
    int p, n, k;
    cin >> p;

    while(p-- > 0){
        scanf("%d %d" , &n, &k);
        if(k >= n-1 || (n-1)%(k+1) != 0)    cout << "Win" << endl;
        else                                cout << "Lose" << endl;
    }

    return 0;
}