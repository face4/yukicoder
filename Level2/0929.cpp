#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int b[n];
    for(int i = 0; i < n; i++)  cin >> b[i];
    int now = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        while(b[i]-- > 0){
            ans += abs(i-now);
            now++;
        }
    }
    cout << ans << endl;
    return 0;
}