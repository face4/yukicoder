// bitDP
#include<iostream>
using namespace std;

string s;

int solve(int used){
    int i, j, k, ret = 0;
    for(i = 0; i < s.length()-2; i++){
        for(j = i+1; j < s.length()-1; j++){
            for(k = j+1; k < s.length(); k++){
                if(used>>i&1 || used>>j&1 || used>>k&1 || s[i]=='0' || s[j]!=s[k] || s[i]==s[j]){
                    continue;
                }

                int t = 100*(s[i]-'0') + 10*(s[j]-'0') + (s[k]-'0');
                t += solve(used ^ 1<<i ^ 1<<j ^ 1<<k);
                ret = max(ret, t);
            }
        }
    }
    return ret;
}

int main(){
    cin >> s;
    cout << solve(0) << endl;
    return 0;
}