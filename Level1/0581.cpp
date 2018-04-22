#include<iostream>
#include<bitset>
#include<sstream>
using namespace std;

int main(){
    long long a, c;
    cin >> a >> c;
    long long b = a^c;
    cout << b << endl;
    return 0;
}