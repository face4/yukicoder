#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    char op;
    cin >> op;
    ll b[m], a[n];
    for(int i = 0; i < m; i++)  cin >> b[i];
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << (op=='+' ? a[i]+b[j] : a[i]*b[j]) << " \n"[j==m-1];
        }
    }
    return 0;
}