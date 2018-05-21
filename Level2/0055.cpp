#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int x[3], y[3];
    for(int i = 0; i < 3; i++)  cin >> x[i] >> y[i];

    int order[3] = {0,1,2};
    bool frag = false;
    int vecx;
    int vecy;

    do{
        vecx = x[order[2]]-x[order[1]];
        vecy = y[order[2]]-y[order[1]];

        if(x[order[1]]-(vecy) == x[order[0]] && (y[order[1]]+vecx) == y[order[0]]){
            frag = true;
            break;
        }
    }while(next_permutation(order, order+3));

    if(frag){
        cout << (x[order[0]] + vecx) << " " << (y[order[0]] + vecy) << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}