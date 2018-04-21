#include<iostream>
using namespace std;

int main(){
    char c;
    int l = 0, r = 0;
    bool frag = false;
    for(; cin >> c;){
        if(c == '#'){
            break;
        }else if(c == '*'){
            frag = true;
        }else if(frag){
            if(c == ')')      l++;
            else if(c == '^') r++;
            frag = false;
        }
    }

    cout << l << " " << r << endl;
    return 0;
}