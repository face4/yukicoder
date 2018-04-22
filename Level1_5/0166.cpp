#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll h, w, n, k;
    cin >> h >> w >> n >> k;
    if((h*w)%n == k%n){
        cout << "YES";
    }else{
        cout << "NO";
    }
    cout << endl;
    return 0;
}