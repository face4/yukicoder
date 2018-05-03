#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i;

    string first = "";
    first += s[0];

    for(i = 1;;i++){
        if(s[i] == '-' || s[i] == '+'){
            break;
        }else{
            first += s[i];            
        }
    }

    char op = s[i++];

    string second = s.substr(i);

    if(op == '+')       cout << stoi(first)-stoi(second) << endl;
    else if(op == '-')  cout << stoi(first)+stoi(second) << endl;

    return 0;
}