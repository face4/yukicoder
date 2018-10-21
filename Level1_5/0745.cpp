#include<iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(d == 10){
        cout << "Impossible" << endl;
    }else{
        cout << "Possible" << endl;
        int ans = 0;
        int bonus = 1;
        while(a+b > 0){
            int used = 100;
            if(b > 0){
                int tmp = min(b, used);
                ans += tmp * bonus * 50;
                b -= tmp;
                used -= tmp;
            }
            if(used > 0 && a > 0){
                int tmp = min(a, used);
                ans += tmp * bonus * 100;
                a -= tmp;
            }
            bonus *= 2;
        }
        cout << ans << endl;
    }

    return 0;
}