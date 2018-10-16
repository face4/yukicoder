#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    
    a *= 60;
    c *= 3600;

    if(a < b){
        cout << -1 << endl;
    }else{
        cout << (c+a-b-1)/(a-b) << endl;
    }
    return 0;
}