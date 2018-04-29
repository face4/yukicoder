#include<iostream>
using namespace std;

int main(){
    int n, v;
    cin >> n;
    int V[n+1] = {};
    
    cin >> v;
    V[1] = v;

    for(int i = 2; i <= n; i++){
        cin >> v;
        V[i] = max(V[i-1], V[i-2] + v);
    }

    cout << V[n] << endl;
    return 0;
}