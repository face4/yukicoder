#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    string s;
    cin >> s;

    bool b = true;
    for(int i = 1; i < s.length(); i++) b &= s[i] == s[i-1];
    if(b){
        cout << s << endl;
        return 0;
    }

    reverse(s.begin(), s.end());
    auto f = [](char x)->int{return x-'0';};

    int g = 0;
    for(int i = 0; i < s.length(); i++){
        for(int j = i+1; j < s.length(); j++){
            if(s[i] == s[j])    continue;
            if(g == 0)  g = 9*abs(f(s[i])-f(s[j]));
            else        g = gcd(g, 9*abs(f(s[i])-f(s[j])));
        }
    }

    for(int gg = g;; gg--){
        if(g%gg)    continue;
        int acc = 0;
        for(int i = 0; i < s.length(); i++){
            acc = acc*10 + f(s[i]);
            acc %= gg;
        }
        if(acc == 0){
            cout << gg << endl;
            return 0;
        }
    }

}