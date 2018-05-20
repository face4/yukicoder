#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll r, c, ans;
    cin >> r >> c;

    if(r != c){
        ans = r/2 * c;
        if(r%2 == 1) ans += (c+1)/2;
    }else{
        if(r%2 == 0)    ans = r*r/4;
        else            ans = (r*r-1)/4+1;
    }
    
    cout << (ans-1) << endl;

    return 0;
}