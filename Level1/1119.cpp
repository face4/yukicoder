#include<iostream>
using namespace std;

int main(){
    int f = 0;
    for(int i = 0; i < 3; i++){
        int x;  cin >> x;
        f |= (x%3==0);
    }
    cout << (f ? "Yes" : "No") << endl;
    return 0;
}