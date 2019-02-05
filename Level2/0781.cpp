#include<iostream>
#include<cmath>
using namespace std;

int memo[10000000] = {};

int main(){
    int x, y;
    cin >> x >> y;

    int tmp = sqrt(10000000);
    for(int i = 0; i <= tmp; i++){
        for(int j = 0; j <= tmp; j++){
            if(i*i+j*j > 10000000)  break;
            memo[i*i+j*j] += 4;
            if(i == 0 || j == 0)    memo[i*i+j*j] -= 2;
        }
    }

    int ans = 0;
    for(int i = x; i <= y; i++){
        ans = max(ans, memo[i]);
    }

    cout << ans << endl;

    return 0;
}