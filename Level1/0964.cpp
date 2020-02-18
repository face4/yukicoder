#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--) cout << j;
    }
    cout << endl;
    return 0;
}