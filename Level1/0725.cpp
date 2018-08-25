#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        if(s[i] != 't') cout << s[i];
        else{
            if(i+7 <= s.length() && s.substr(i,7) == "treeone"){
                cout << "forest";
                i += 6;
            }else{
                cout << s[i];
            }
        }
    }
    cout << endl;

    return 0;
}