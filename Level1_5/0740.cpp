#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    int ans = 0;
    while(1){
        if(inRange((ans%12)+1, p, p+q)){
            n -= 2*m;
        }else{
            n -= m;
        }
        ans++;
        if(n <= 0)  break;
    }

    cout << ans << endl;

    return 0;
}