#include<iostream>
#include<algorithm>
using namespace std;

int getNum(string s){
    if(s == "ne")   return 0;
    if(s == "ushi")   return 1;
    if(s == "tora")   return 2;
    if(s == "u")   return 3;
    if(s == "tatsu")   return 4;
    if(s == "mi")   return 5;
    if(s == "uma")   return 6;
    if(s == "hitsuji")   return 7;
    if(s == "saru")   return 8;
    if(s == "tori")   return 9;
    if(s == "inu")   return 10;
    if(s == "i")   return 11;
    
    return -1;
}

int main(){
    int n;
    cin >> n;
    int A[12] = {};
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        A[getNum(s)]++;
    }
    sort(A, A+12);
    if(A[11]*2-1 <= n)  cout << "YES";
    else                cout << "NO";

    cout << endl;
    return 0;
}