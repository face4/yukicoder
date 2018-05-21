#include<iostream>
using namespace std;

int main(){
    int n, m, c;
    cin >> n >> m >> c;

    if(n%2 == 1 && m%2 == 1){
        cout << "NO" << endl;
    }else if(n == 1 || m == 1){
        if(n+m == 3)    cout << "YES" << endl;
        else            cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    
    return 0;
}