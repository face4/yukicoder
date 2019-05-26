#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = INT_MAX;
    for(int i = 1; i*i <= a+b; i++){
        if((a+b)%i || i==a || i==b || a==b/*redundant*/) continue;
        int t = i;
        if((a+t)%b==0 && (b+t)%a==0){
            ans = i;
            break;
        }
        t = (a+b)/i;
        if(t == a || t == b)    continue;
        if((a+t)%b==0 && (b+t)%a==0){
            ans = min(ans, t);
        }
    }
    cout << (ans==INT_MAX ? -1 : ans) << endl;
    return 0;
}