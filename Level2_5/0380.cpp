// 相当めんどくさい、空白の処理やらなにやら
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define print(x, a, b) if(x) cout << a << endl; else cout << b << endl

bool isSymbol(char x){
    bool small = 'a' <= x && x <= 'z';
    bool large = 'A' <= x && x <= 'Z';
    bool number = '0' <= x && x <= '9';
    if(small || large || number)    return false;
    else                            return true;
}

bool startsWith(string str, string pre){
    int s = str.length(), p = pre.length();
    if(s < p)   return false;

    int j;
    for(j = 0; j < p; j++){ 
        if(str[j] != pre[j])  break;
    }

    return j == p;
}

bool check(string s, string gobi){
    reverse(s.begin(), s.end());
    reverse(gobi.begin(), gobi.end());

    int pos = 0;
    while(pos < s.length() && isSymbol(s[pos])){
        pos++;
    }

    if(pos > 3) return false;

    bool judge = true;
    for(int i = 0; i < gobi.length(); i++){
        if(pos+i > s.length()-1 || isSymbol(s[pos+i]))  judge = false;
        else                    s[pos+i] = tolower(s[pos+i]);
    }

    if(!judge)  return false;

    return startsWith(s.substr(pos), gobi);
}

string people[5] = {"digi ", "petit ", "gema ", "piyo ", "rabi "};
string suffix[4] = {"nyo", "nyu", "gema", "pyo"};

int main(){
    string s;
    while(getline(cin, s)){
        int person;
        for(person = 0; person < 5; person++){
            if(startsWith(s, people[person]))   break;
        }

        if(person == 5){
            cout << "WRONG!" << endl;
            continue;
        }

        if(person == 4){
            bool judge = false;
            for(int i = people[person].length(); i < s.size(); i++){
                if(!isSymbol(s[i]))    judge = true;
            }
            print(judge, "CORRECT (maybe)", "WRONG!");
            continue;
        }

        print(check(s.substr(people[person].length()), suffix[person]) ,"CORRECT (maybe)", "WRONG!");
    }
    return 0;
}