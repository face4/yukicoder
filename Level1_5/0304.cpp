#include<iostream>
using namespace std;

int main(){
    int n = 0;
    while(true){
        string s;
        if(n < 100) s.append("0");
        if(n < 10)  s.append("0");
        s.append(to_string(n));
        cout << s << endl << flush;
        getline(cin, s);
        if(s == "unlocked") break;
        n++;
    }
    return 0;
}