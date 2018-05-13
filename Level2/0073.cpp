#include<iostream>
using namespace std;

int main(){
    int A[26];
    for(int i = 0; i < 26; i++)  cin >> A[i];

    long long ans = 1;
    if(A['d'-'a'] > 0)  ans *= A['d'-'a'];
    else                ans = 0;
    if(A['e'-'a'] > 0)  ans *= A['e'-'a'];
    else                ans = 0;
    if(A['h'-'a'] > 0)  ans *= A['h'-'a'];
    else                ans = 0;
    if(A['r'-'a'] > 0)  ans *= A['r'-'a'];
    else                ans = 0;
    if(A['w'-'a'] > 0)  ans *= A['w'-'a'];
    else                ans = 0;
    if(A['o'-'a'] > 1)  ans *= (A['o'-'a']/2*(A['o'-'a']-A['o'-'a']/2));
    else                ans = 0;
    if(A['l'-'a'] > 2){
        int num = A['l'-'a'];
        num -= 3;
        int light = 2, right = 1;
        int ma = 0;
        for(int i = 0; i <= num; i++){
            int l = light+i;
            int r = right+num-i;
            ma = max(ma, l*(l-1)/2*r);
        }

        ans *= ma;
    }else{
        ans = 0;
    }

    cout << ans << endl;
    return 0;
}