#include<iostream>
using namespace std;

int main(){
    long long a, b, res = 0;
    cin >> a >> b;
    if(a > b){
        res += a-b-1;
        res += 2000000000-a;
    }else{
        res += b-2;
    }

    cout << res << endl;
    return 0;
}