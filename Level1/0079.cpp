#include<iostream>
using namespace std;

int main(){
    int n, t, V[7] = {};
    cin >> n;
    while(n-- > 0){
        cin >> t;
        V[t]++;
    }

    int maxValue = -1, maxIndex;
    for(int i = 1; i <= 6; i++){
        if(maxValue <= V[i]){
            maxIndex = i;
            maxValue = V[i];
        }
    }

    cout << maxIndex << endl;
    return 0;
}
