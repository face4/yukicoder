#include<iostream>
using namespace std;

int main(){
    int a[6];
    for(int i = 0; i < 6; i++)  cin >> a[i];
    int odd = 0;
    for(int i = 0; i < 6; i+=2){
        odd += a[i]%2;
    }
    cout << (odd%2 == 1 ? ":-(" : ":-)") << endl;
    return 0;
}