#include<iostream>
using namespace std;
typedef long long ll;

#define NUM 1000000007

int main(){
    int n;
    ll c1, d1, ans = 0;
    cin >> n;
    while(n-- > 0){
        cin >> c1 >> d1;
        ll people = ((c1+1)/2)%NUM;
        ans += ((d1%NUM) * people) % NUM;
    }

    cout << (ans%NUM) << endl;
    return 0;
}