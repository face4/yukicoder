#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long f0 = 0, f1 = 1;
    int index = 3;

    while(index <= n){
        long long tmp = (f0+f1)%m;
        f0 = f1;
        f1 = tmp;
        index++;
    }

    cout << f1 << endl;
    return 0;
}