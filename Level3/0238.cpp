#include<iostream>
using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i])    return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    
    int n = s.length();

    if(isPalindrome(s)){
        s.insert(s.begin() + n/2, s[n/2]);
    }else{
        string ans = "";
        
        int diffpos;
        for(diffpos = 0;; diffpos++)    if(s[diffpos] != s[n-1-diffpos])    break;
        
        s.insert(s.begin() + diffpos, 'a');
        for(int i = 0; i < 26; i++){
            if(isPalindrome(s)) ans = s;
            s[diffpos]++;
        }
        s.erase(s.begin()+diffpos);

        s.insert(s.begin() + n - diffpos, 'a');
        for(int i = 0; i < 26; i++){
            if(isPalindrome(s)) ans = s;
            s[n-diffpos]++;
        }
        s.erase(s.begin() + n - diffpos); // needless

        if(ans != "")   s = ans;
        else            s = "NA";
    }

    cout << s << endl;

    return 0;
}