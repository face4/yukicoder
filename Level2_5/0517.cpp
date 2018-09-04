#include<iostream>
#include<map>
using namespace std;

int main(){
    int n, m, length = 0;
    map<char,char> acc;
    string s;
    bool a = true;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int i = 0; i < s.length()-1; i++){
            acc[s[i]] = s[i+1];
        }
        length += s.length();
    }

    if(length == 1){
        cin >> m;
        string t;
        cin >> t;
        if(m == 1 && s == t){
            cout << t << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> s;
        for(int i = 0; i < s.length()-1; i++){
            if(acc.count(s[i])){
                if(acc[s[i]] != s[i+1]) a = false;
            }else{
                acc[s[i]] = s[i+1];
            }
        }
    }

    if(!a){
        cout << -1 << endl;
        return 0;
    }

    string ans = "-1";
    for(char c = 'A'; c <= 'Z'; c++){
        if(!acc.count(c))   continue;

        string tmp{c};
        char x = c;

        while(acc.count(x)){
            x = acc[x];
            tmp += x;
        }

        if(tmp.length() == length){
            ans = tmp;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}