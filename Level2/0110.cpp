#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int nw, nb;
    
    cin >> nw;
    int W[nw];
    for(int i = 0; i < nw; i++) cin >> W[i];

    cin >> nb;
    int B[nb];
    for(int i = 0; i < nb; i++) cin >> B[i];

    sort(W, W+nw);
    sort(B, B+nb);

    int now, ansW, ansB, posW, posB;
    
    now = W[0], ansW = 1, posW = 1, posB = 0;
    while(1){
        while(now >= B[posB] && posB < nb){
            posB++;
        }

        if(posB == nb)  break;

        ansW++; now = B[posB];

        while(now >= W[posW] && posW < nw){
            posW++;
        }

        if(posW == nw)  break;
        
        ansW++; now = W[posW];
    }
    
    now = B[0], ansB = 1, posW = 0, posB = 1;
    while(1){
        while(now >= W[posW] && posW < nw){
            posW++;
        }

        if(posW == nw)  break;
        
        ansB++; now = W[posW];
        
        while(now >= B[posB] && posB < nb){
            posB++;
        }

        if(posB == nb)  break;

        ansB++; now = B[posB];
    }

    cout << max(ansW,ansB) << endl;
    return 0;
}