#include<iostream>
#include<iomanip>
using namespace std;

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    double n, m, p;
    cin >> n >> m >> p;
    double d;
    if(n == 1 && m == 1){
        d = p;
    }else if(n == 1 || m == 1){
        double x = max(n, m);
        d = p*p*min(2.0, x) + p*p*p*max(0.0,x-2);
    }else if(n >= 2 && m >= 2){
        d = p*p*p*4+p*p*p*p*2*(n-2+m-2)+p*p*p*p*p*(n-2)*(m-2);
    }else{
        d = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                double r = p;
                for(int k = 0; k < 4; k++){
                    int ni = i+di[k], nj = j+dj[k];
                    if(inRange(ni,0,n)&&inRange(nj,0,m))  r *= p;
                }
                d += r;
            }
        }
    }
    cout << fixed << setprecision(12) << d << endl;
    return 0;
}