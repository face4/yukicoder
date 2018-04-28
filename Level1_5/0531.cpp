#include<iostream>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    int res = 0;
    if(m >= n){
        res = 1;
    }else if(n%2 == 0){
        if(m >= (n/2)){
            res = 2;
        }else{
            res = -1;
        }
    }else{
        res = -1;
    }
    cout << res << endl;
    return 0;
}