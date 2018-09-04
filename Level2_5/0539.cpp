#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;

int main(){
    int t;
    scanf("%d\n", &t);

    while(t-- > 0){
        string s;
        getline(cin, s);

        string res = "";
        for(int i = s.length()-1; i >= 0; i--){
            if(isdigit(s[i])){
                int carry = 1;
                while(i >= 0 && isdigit(s[i])){
                    int val = carry + (s[i] - '0');
                    carry = val/10;
                    val %= 10;
                    char next = '0' + val;
                    string t{next};
                    res += t;
                    i--;
                }
                if(carry)   res += "1";

                string rest = s.substr(0, ++i);
                reverse(rest.begin(), rest.end());
                res += rest;
                
                break;
            }else{
                res += s.substr(i,1);
            }
        }

        reverse(res.begin(), res.end());
        cout << res << endl;
    }

    return 0;
}