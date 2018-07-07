#include<iostream>
#include<cctype>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 0, state = 1, paren = 1;

    int len = s.length();

    for(int i = 0; i < len;){
        if(isdigit(s[i])){
            int tmp = 0;
            while(i < len && isdigit(s[i])){
                tmp = tmp * 10 + s[i] - '0';
                i++;
            }
            ans += paren * state * tmp;
        }else{
            if(s[i] == '-'){
                state = -1;
            }else if(s[i] == '+'){
                state = 1;
            }else if(s[i] == '('){
                if(state == -1){
                    paren = -1;
                    state = 1;
                } 
            }else if(s[i] == ')'){
                paren = 1;
            }
            i++;
        } 
    }

    cout << ans << endl;
    return 0;
}