#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    int ans = 0;
    string s;
    cin >> s;

    stack<string> a;

    for(int index = 0; index < s.length();){
        if(s[index] == '*' || s[index] == '+'){
            string o{s[index++]};
            a.push(o);
        }else{
            string x = "";        
            while(s[index] != '*' && s[index] != '+'){
                x += s[index++];
            }
            if(a.size() == 2){
                string ope = a.top(); a.pop();
                int first = stoi(a.top());  a.pop();
                if(ope == "+"){
                    a.push(to_string( (first * stoi(x)) ));
                }else if(ope == "*"){
                    a.push(to_string( (first + stoi(x)) ));
                }
            }else{
                a.push(x);            
            }
        }
    }

    cout << stoi(a.top()) << endl;
    return 0;
}