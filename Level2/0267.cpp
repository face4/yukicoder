#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int ston(char s){
    if(s == 'D')    return 0;
    if(s == 'C')    return 1;
    if(s == 'H')    return 2;
    if(s == 'S')    return 3;
    return -1;
}

int nton(char s){
    if(s == 'A')    return 1;
    if(s == 'T')    return 10;
    if(s == 'J')    return 11;
    if(s == 'Q')    return 12;
    if(s == 'K')    return 13;
    
    return s-'0';
}

bool comp(string s, string t){
    if(s[0] == t[0]){
        return nton(s[1]) < nton(t[1]);
    }else{
        return ston(s[0]) < ston(t[0]);
    }
}

int main(){
    int n;
    cin >> n;

    vector<string> cards(n);

    for(int i = 0; i < n; i++)  cin >> cards[i];

    sort(cards.begin(), cards.end(), comp);

    for(int i = 0; i < n; i++){
        if(i != 0)  cout << " ";
        cout << cards[i];
    }

    return 0;
}