#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    string s;
    for(int i = 0; i < t; i++){
        cin >> s;
        bool judge = true;

        int tmp = 0, w = 0, g = 0, bus = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'G'){
                tmp++;
                g++;
                if(w < g)   judge = false;
            }else if(s[i] == 'R'){
                tmp--;
                bus++;
                if(tmp < 0) judge = false;
            }else if(s[i] == 'W'){
                w++;
            }
        }

        if(tmp != 0)    judge = false;
        if(w < bus) judge = false;
        if(s[s.length()-1] != 'R')  judge = false;

        for(int i = s.length()-1; i >= 0 && s[i] != 'G'; i--){
            if(s[i] == 'W') judge = false;
        }

        if(judge)   cout << "possible" << endl;
        else        cout << "impossible" << endl;
    }

    return 0;
}