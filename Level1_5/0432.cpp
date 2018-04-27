#include<iostream>
using namespace std;

int main(){
    int t;
    string s;
    cin >> t;

    while(t-- > 0){
        cin >> s;
        while(s.length() != 1){
            string t = "";
            for(int i = 0; i < s.length()-1; i++){
                int a = (char)(s[i]-'0');
                int b = (char)(s[i+1]-'0');
                int c = (a+b >= 10) ? 1+(a+b)%10 : a+b;
                t.append(to_string(c));
            }
            s = t;
        }
        cout << s << endl;
    }

    return 0;
}