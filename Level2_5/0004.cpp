#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool b[10001] = {};
    b[0] = true;

    int a, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = 10000; j >= 0; j--) if(b[j] && j+a <= 10000)  b[j+a] = true;
        sum += a;
    }

    bool judge = sum % 2 == 0 && b[sum/2];

    if(judge)   cout << "possible" << endl;
    else        cout << "impossible" << endl;

    return 0;
}
