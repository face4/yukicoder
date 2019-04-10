#include<iostream>
using namespace std;

int main(){
    int a[13] = {};
    string s;
    cin >> s;
    for(char c : s){
        a[c-'a']++;
    }
    int two = 0, one = 0;
    for(int x : a){
        if(x == 2)  two++;
        if(x == 1)  one++;
    }
    if(two > 1 || (two == 0 && one != 13) || (two == 1 && one != 11)){
        cout << "Impossible" << endl;
    }else{
        for(int i = 0; i < 13; i++){
            if(two == 1 && a[i] == 0){
                cout << (char)('a' + i) << endl;
            }else if(two == 0){
                cout << (char)('a' + i) << endl;
            }
        }
    }
    return 0;
}