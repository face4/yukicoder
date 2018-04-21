#include<iostream>
using namespace std;

int main(){
    char A[10] = "yukicoder";
    int i;
    char c;
    for(i = 0; i < 9; i++){
        cin >> c;
        if(c == '?') break;
    }
    cout << A[i] << endl;
    return 0;
}