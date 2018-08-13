#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 0;

    for(int i = 0; i < s.length()-1; i++){
        for(int j = i+1; j < s.length(); j++){
            int tmp = j-i+1;
            for(int k = 0; k < (j-i+1)/2; k++){
                if(s[i+k] != s[j-k])    tmp -= 2;
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;

    return 0;
}