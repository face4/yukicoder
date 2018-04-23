#include<iostream>
using namespace std;

int main(){
    int odd = 0, even = 0, n, x;
    cin >> n;
    while(n-- > 0){
        cin >> x;
        if(abs(x) % 2 == 0) even++;
        else                odd++;
    }
    cout << abs(even-odd) << endl;
    return 0;
}