#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int ans = 0;
    for(int i = 30; i >= 0; i--){
        int judge = 0;
        for(int j = 0; j < n; j++){
            judge += (a[j]>>i)&1;
        }
        if(judge == 0 || judge == n)    continue;
        ans += (1<<i);
    }

    cout << ans << endl;

    return 0;
}