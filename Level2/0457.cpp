#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int left = 0, right = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            bool astaL = false;
            int wedgeL = 0, wedgeR = 0;
            bool flagL = false, flagR = false;
            for(int j = i+1; j < s.length(); j++){
                if(s[j] == '*'){
                    astaL = true;
                    if(wedgeR >= 2) flagR = true;
                }else if(s[j] == ')'){
                    if(flagL)   left++;
                    if(flagR)   right++;
                }else if(s[j] == '^'){
                    wedgeR++;
                    if(astaL){
                        wedgeL++;
                        if(wedgeL >= 2) flagL = true;
                    }
                }
            }
        }
    }
    cout << right << " " << left << endl;

    return 0;
}