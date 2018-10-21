#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n == 0){
        cout << 0 << endl;
    }else{
        cout << "0.";
        for(int i = 0; i < n/6; i++)    cout << "142857";
        for(int i = 0; i < n%6; i++)    cout << "142857"[i];
        cout << endl;
    }
    return 0;
}