#include<iostream>
#include<cfloat>
#include<cmath>
#include<iomanip>
using namespace std;

char mat[52][52];
int h, w;

double solve(int x, int y){
    double dist = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(mat[i][j] == '1'){
                dist += sqrt(pow(x-i, 2.0) + pow(y-j, 2.0));
            }
        }
    }
    return dist;
}

int main(){
    cin >> h >> w;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> mat[i][j];
        }
    }

    double ans = DBL_MAX;

    for(int i = 1; i <= w; i++){
        ans = min(ans, solve(0, i));
        ans = min(ans, solve(h+1, i));
    }

    for(int i = 1; i <= h; i++){
        ans = min(ans, solve(i,0));
        ans = min(ans, solve(i,w+1));
    }

    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}