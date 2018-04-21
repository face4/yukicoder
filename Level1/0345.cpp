// いける、と思って実装したら思いのほかうまくいかなくて
// 答えを見た.O(n)で解ける.

#include<iostream>
#include<string>
using namespace std;

int main(){
    string S;
    cin >> S;
    int n = S.length();
    int w2 = n, w1 = n;
    int minLen = n+1;

    for(int i = n-1; i >= 0; i--){
        if(S[i] == 'w'){
            w2 = w1;
            w1 = i;
        }
        if(S[i] == 'c' && w2 != n){
            minLen = min(minLen, w2-i+1);
        }
    }

    if(minLen == n+1)   minLen = -1;
    cout << minLen << endl;
    return 0;
}