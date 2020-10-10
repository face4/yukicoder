#include<iostream>
#include<algorithm>
#include<numeric>
#include<iomanip>
using namespace std;

int main(){
    double d[3];
    for(int i = 0; i < 3; i++)  cin >> d[i];
    double s = accumulate(d, d+3, 0.0);
    cout << fixed << setprecision(12) << (s-*min_element(d,d+3))/s << endl;
    return 0;
}