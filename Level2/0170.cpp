#include<iostream>
using namespace std;

long fact(long i){
    if(i == 1)  return 1;

    return i * fact(i-1);
}

int main(){
    string s;
    cin >> s;
    int hindo[26] = {};
    for(char c : s){
        hindo[(int)(c - 'A')]++;
    }
    long long ans = fact(s.length());

    for(int i = 0; i < 26; i++){
        if(hindo[i] > 1){
            ans /= fact(hindo[i]);
        }
    }

    cout << ans-1 << endl;
    return 0;
}