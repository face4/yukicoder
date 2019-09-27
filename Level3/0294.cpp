#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

ll comb(int n, int c){
    ll ret = 1;
    for(int i = 0; i < c; i++){
        ret *= (n-i);
        ret /= i+1;
    }
    return ret;
}

int main(){
    int n;
    cin >> n;

    n--;
    int len = 3;
    while(true){
        ll tmp = 0;
        for(int five = 2; five+1 <= len; five += 3){
            tmp += comb(len-1, five);
        }
        if(n < tmp) break;
        n -= tmp;
        len++;
    }

    for(int i = 0; i < 1<<(len-1); i++){
        int popcnt = 0;
        for(int j = 0; j < len-1; j++){
            if((i>>j)&1)    popcnt++;
        }
        if(popcnt%3 == 2){
            n--;
            if(n < 0){
                string ret = "5";
                for(int j = 0; j < len-1; j++){
                    ret += "35"[(i>>j)&1];
                }
                reverse(ret.begin(), ret.end());
                cout << ret << endl;
                return 0;
            }
        }
    }
}