#include<iostream>
using namespace std;

int main(){
    int n, g, d, maxIndex = 0, maxExp = -1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> g >> d;
        if(maxExp < g - 30000*d){
            maxIndex = i;
            maxExp = g-30000*d;
        }
    }

    if(maxExp * 6 >= 30000*100){
        cout << "YES" << endl;
        for(int i = 0; i < 6; i++)  cout << maxIndex+1 << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}