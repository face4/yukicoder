#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; 5*i <= n; i++){
        for(int j = 0; j <= i && 5*i+2*j <= n; j++){
            ans += (n-(5*i+2*j))%3 == 0;
        }
    }
    cout << ans << endl;
    return 0;
}