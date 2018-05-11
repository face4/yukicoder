#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a; i <= b; i++){
        if((a+i+b)%3 == 0)  ans++;
    }
    cout << ans << endl;
    return 0;
}