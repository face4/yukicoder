#include<iostream>
using namespace std;

// MLE?
static bool d[20001][20001] = {};

int main(){
    int n;
    cin >> n;

    int x, y, cnt = 0;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        bool judge = true;
        // 4 x 10^7
        for(int j = max(0, x-20); judge && j <= min(20000, x+20); j++){
            for(int k = max(0, y-20); judge && k <= min(20000, y+20); k++){
               if(d[j][k] && (j-x)*(j-x)+(k-y)*(k-y) < 400) judge = false;
            }
        }

        if(judge){
            cnt++;
            d[x][y] = true;
        }
    }

    cout << cnt << endl;

    return 0;
}