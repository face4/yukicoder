#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ma = n, step = 0;
    while(n != 1){
        if(n%2 == 0)    n = n/2;
        else {
            n = 3*n + 1;
            ma = max(n, ma);
        }
        step++;
    }
    cout << step << endl;
    cout << ma << endl;
    return 0;
}