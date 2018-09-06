#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    if(m == 0 && n <= 2)    cout << "Impossible" << endl;
    else                    cout << "Possible" << endl;
    return 0;
}