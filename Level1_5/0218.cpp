#include<iostream>
using namespace std;

int main(){
    int a, b, c, bNum, cNum;
    cin >> a >> b >> c;
    bNum = a / b + (a % b == 0 ? 0 : 1);
    cNum = a / c + (a % c == 0 ? 0 : 1);
    if(bNum * 2.0 / 3.0 >= cNum){
        cout << "YES";
    }else{
        cout << "NO";
    }
    cout << endl;
    return 0;
}