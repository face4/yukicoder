#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    bool frag;
    int size = s.size();
    int i;

    for(i = size-1; i > 1; i--){
        for(int j = 0; j <= size-i; j++){
            frag = true;
            for(int k = 0; k < i/2; k++)    if(s[j+k] != s[j+i-1-k])  frag = false;
            if(frag)    break;
        }
        if(frag)    break;
    }

    if(frag)    cout << i << endl;
    else        cout << 1 << endl;
    
    return 0;
}