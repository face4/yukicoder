#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool valid = true;
    for(int i = 0; i < s.size();){
        valid &= s.substr(i,2)=="AC";
        i += 2;
        if(i < s.size())    valid &= s[i++]==',';
    }
    cout << (valid ? "Done!" : "Failed...") << endl;
    return 0;
}