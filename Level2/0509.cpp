#include<iostream>
using namespace std;

int main(){
    int n, circles = 0;
    cin >> n;
    int length = to_string(n).length();
    int A[10] = {1,0,0,0,1,0,1,0,2,1};

    for(int i = 0; i < length; i++){
        circles += A[n%10];
        n /= 10;
    }

    if(1+circles > length)  cout << length*2 + circles + 1 << endl;
    else                    cout << length + (circles + 1)*2 << endl;
    return 0;
}