#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char c;
    string s = "";
    for(; cin >> c; ){
        if(c == '>')      s.insert(0, "<");
        else if(c == '<') s.insert(0,">");
    }
    cout << s << endl;
    return 0;
}