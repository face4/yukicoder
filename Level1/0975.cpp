#include<iostream>
using namespace std;

int main(){
    int x, n, m;
    cin >> x >> n >> m;
    bool a = false, b = false;
    for(int i = 0; i < n; i++){
        int j;  cin >> j;
        a |= j==x;
    }
    for(int i = 0; i < m; i++){
        int j;  cin >> j;
        b |= j==x;
    }
    if(a){
        if(b)   cout << "MrMaxValu" << endl;
        else    cout << "MrMax" << endl;
    }else{
        if(b)   cout << "MaxValu" << endl;
        else    cout << -1 << endl;
    }
    return 0;
}