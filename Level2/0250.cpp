#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int q;
    cin >> q;

    ll d,x,t,times;
    while(q-- > 0){
        cin >> d >> x >> t;
        times = 1;

        for(int i = 1; i <= d-1; i++){
            times = times * (x+i) / i;
            if(times > t || times > 1e15){
                break;
            }
        }
        if(times <= t)  cout << "AC" << endl;
        else            cout << "ZETUBOU" << endl;
    }

    return 0;
}