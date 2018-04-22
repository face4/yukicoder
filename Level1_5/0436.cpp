#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i = -1;
    while(s[++i] != 'w');
    if(s.size() - i > i-2+1){
        cout << i-2+1 << endl;
    }else{
        cout << s.size() - i << endl;
    }
    return 0;
}