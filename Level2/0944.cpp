#include<iostream>
using namespace std;

bool b[10000001] = {};

int main(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        sum += x;
        b[sum] = true;
    }
    int ans = 0;
    for(int i = 1; i*i <= sum; i++){
        if(sum%i) continue;
        if(sum/i <= n){
            int j = 1;
            while(j*i <= sum && b[j*i])   j++;
            if(j*i > sum) ans = max(ans, sum/i);
        }
        if(i <= sum){
            int j = 1;
            while(j*(sum/i) <= sum && b[j*(sum/i)])   j++;
            if(j*(sum/i) > sum) ans = max(ans, i);
        }
    }
    cout << ans << endl;
    return 0;
}