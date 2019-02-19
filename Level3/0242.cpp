#include<iostream>
#include<iomanip>
using namespace std;

// 12本のビンゴ列は独立(かつ同一と見なせる.はず.)
int main(){
    double n;
    cin >> n;
    cout << fixed << setprecision(12) << (n > 4 ? n*(n-1)*(n-2)*(n-3)*(n-4)/99/98/97/96/95*12 : 0) << endl;
    return 0;
}