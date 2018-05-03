#include<iostream>
using namespace std;

int m,x;

int solve(int n){
    if(n == 1)  return x;
    if(n%2 == 0){
        int a = solve(n/2)%m;
        return (a*a)%m;
    }else{
        int a = solve((n-1)/2)%m;
        return ( (a*a)%m *x)%m;
    }
}

int main(){
    cin >> m;
    x = (2017*2017)%m;

    int right = solve(2017);

    cout << (2017+right)%m << endl;
    return 0;
}