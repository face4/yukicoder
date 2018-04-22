#include<iostream>
using namespace std;

int main(){
    int h = 10, m = 0;
    int a;
    cin >> a;
    a /= 10;
    a *= 6;
    m += a;
    if(m >= 60){
        h += m / 60;
        m -= m / 60 * 60;
    }
    cout << h << ":" << (m < 10 ? "0" : "") << m << endl;
    return 0; 
}