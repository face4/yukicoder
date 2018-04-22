#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int res = 0, now = 1, bis;
    cin >> bis;
    while(now < bis){
        now *= 2;
        res++;
    }
    cout << res << endl;
    return 0;
}