#include<iostream>
using namespace std;

int main(){
    long long n, a, tmp, sum = 0;
    cin >> n >> a;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        sum += tmp;
    }

    if( ((double)sum / n) == a ) cout << "YES";
    else                         cout << "NO";

    cout << endl;
    return 0;
}