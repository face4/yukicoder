#include<iostream>
using namespace std;

// 成功確率pのベルヌーイ試行が成功するまで試行を行い続けるとき、
// 試行回数の期待値は1/p
int main(){
    int p, q;
    cin >> p >> q;
    cout << min(p, q) << endl;
    return 0;
}