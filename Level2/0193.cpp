#include<iostream>
using namespace std;

int calc(string s){
    int ans = 0;
    char op = '+';

    int b = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0'){
            b = b*10 + s[i]-'0';
        }else{
            if(op == '+')       ans += b;
            else if(op == '-')  ans -= b;

            op = s[i];
            b = 0;
        }
    }

    if(op == '+')       ans += b;
    else if(op == '-')  ans -= b;

    return ans;
}

int main(){
    string s;
    cin >> s;
    
    int len = s.length();
    s += s;

    int ans = -1e9;

    for(int i = 0; i < len; i++){
        string sub = s.substr(i,len);
        char a = sub[0];
        char b = sub[len-1];

        if(a < '0' || b < '0')  continue;

        ans = max(ans, calc(sub));
    }

    cout << ans << endl;
    return 0;
}