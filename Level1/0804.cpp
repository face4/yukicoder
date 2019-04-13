#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min({a, d/(c+1), b/c}) << endl;
    return 0;
}