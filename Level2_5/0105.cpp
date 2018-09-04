#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const double EPS = 0.00001;
const double PI = 2 * acos(0.0);
#define Equals(a,b) abs(a-b) < EPS
#define inRange(x,a,b) a <= x && x <= b

int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        double x, y;
        cin >> x >> y;
        double ans = atan2(y, x);
        ans = ans / PI * 180 + 180;
        
        // dump
        for(int i = 0; i < 5; i++)  cin >> x >> y;

        while(ans > 51) ans -= 60;
        cout << fixed << setprecision(10) << abs(ans) << endl;
    }

    return 0;
}