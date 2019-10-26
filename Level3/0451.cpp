// overflow?
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll b[n];
    for(int i = 0; i < n; i++)  cin >> b[i];
    ll low = 1, high = 1e18, acc = 0;
    int sign = 1;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            acc *= -1;
            sign *= -1;
            acc += b[i];
        }else{
            acc -= b[i];
        }
        if(sign == 1){
            low = max(low, 1-acc);
        }else{
            high = min(high, acc-1);
        }
    }
    if(low > high){
        cout << -1 << endl;
        return 0;
    }
    cout << n+1 << endl << low << endl;
    for(int i = 0; i < n; i++){
        low = (low-b[i])*(2*(i%2)-1);
        cout << low << endl;
    }
    return 0;
}