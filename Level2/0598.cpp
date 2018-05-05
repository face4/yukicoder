#include<iostream>
using namespace std;

int main(){
    int n, x, a, b;
    cin >> n >> x >> a >> b;

    int max = 1<<(n-1);
    int attack = x/a + (x%a == 0 ? 0 : 1);
    int heal = (max-x)/b + ((max-x)%b == 0 ? 0 : 1);
    cout << min(attack,heal) << endl;
    return 0;
}