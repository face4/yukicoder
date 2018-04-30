#include<iostream>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    string res = "";
    if(n > d){
        for(int i = 0; i < d; i++)  res += "A";
        for(int i = 0; i < n-d;i++) res += "C";
    }else{
        for(int i = 0; i < 2*n-d; i++)  res += "A";
        for(int i = 0; i < d-n; i++)    res += "B";
    }
    cout << res << endl;
    return 0;
}