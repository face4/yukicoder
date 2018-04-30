#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long ans = n;
    for(long long i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            if(i != 2)      ans = min(ans, i);
            if(n/i != 2)    ans = min(ans, n/i);
        }
    }

    cout << ans << endl;
    return 0;
}