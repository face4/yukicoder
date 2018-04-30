#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int len = s.length();
    long long w = 0;
    long long res = 0; 
    char c;

    for(int i = 1; i <= len; i++){
        c = s[len-i];
        if(c == 'c' && w >= 2){
            res += w*(w-1)/2;
        }
        if(c == 'w')    w++;
    }

    cout << res << endl;
    return 0;
}