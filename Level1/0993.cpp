#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length();){
        if(i+1 < s.length() && s.substr(i,2)=="ao"){
            cout << "ki";
            i += 2;
        }else{
            cout << s[i++];
        }
    }
    cout << endl;
    return 0;
}