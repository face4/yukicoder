#include<iostream>
using namespace std;

int main(){
    unsigned int n;
    scanf("%ud", &n);
    if(n % 4 == 3)  cout << "X" << endl;
    else            cout << "O" << endl;
    return 0;
}